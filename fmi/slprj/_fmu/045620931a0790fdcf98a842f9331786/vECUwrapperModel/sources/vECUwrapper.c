#include "vECUwrapperModel_macros.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/socket.h>

#include "vECUwrapper.h"

#define PORT 7789
#define BUFFER_SIZE 256

int server_fd, new_socket;

int initSocket(int PortNumber)
{
    int r = 0;
    
    struct sockaddr_in address;

    int addrlen = sizeof(address);

    // 1. Create Socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        r = 1;
    }

    // 2. Set Address
    address.sin_family = AF_INET;           // IPv4
    address.sin_addr.s_addr = INADDR_ANY;   // Receive from all interface
    address.sin_port = htons(PortNumber);
    
    // 3. Bind address to socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        close(server_fd);
        r = 2;
    }

    // 4. Listen (Wait connection)
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed");
        close(server_fd);
        r = 3;
    }

    // 5. Accept client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
    {
        perror("accept failed");
        close(server_fd);
        r = 4;
    }

    return r;

}

void deinitSocket(void)
{
    close(server_fd);
    close(new_socket);
}

// hrkim : SocketToFMI -> ascii to string block -> output
int SocketToFMI(unsigned char *canFrame)
{
    char buffer[BUFFER_SIZE] = {0};
    int read_bytes;
    int r = 0;

    memset(canFrame, 0, 256);

    read_bytes = read(new_socket, buffer, BUFFER_SIZE);

    if (read_bytes < 0)
    {
        perror("Error reading from socket");
        r = read_bytes;
    }

    else if (read_bytes == 0)
    {
        printf("No data received from socket\n");
        r = 1;
    }

    else
    {
        buffer[read_bytes] = '\0';

        char *token = strtok(buffer, ",");

        if (strcmp(token, "complete") == 0)
        {
            printf("Received complete message\n");
        }

        token = strtok(NULL, ",");

        if (token != NULL && strcmp(token, "can") == 0)
        {

            token = strtok(NULL, ",");
            
            if (token != NULL)
            {
                snprintf((char*)canFrame, 256, "1-%s", token);
            }
        }
    }
    
    return r;
}

// hrkim : intput -> string to ascii -> FMIToSocket
int FMIToSocket(double stepSize, unsigned char *canFrame)
{
    int r = 0;
    ssize_t sent_bytes;
    char command[BUFFER_SIZE] = {0};

    // Check if the socket is valid
    if (new_socket <= 0)
    {
        printf("Socket is not connected\n");
        return 1;
    }

    if (canFrame[0] != '1')
    {
        snprintf(command, BUFFER_SIZE, "dostep,%f", stepSize);
        sent_bytes = write(new_socket, command, strlen(command));

        if (sent_bytes < 0)
        {
            perror("Error sending data to socket");
            r = 2;
        }
        else
        {
            printf("Sent %s command to vECU\n", command);
        }
    }
    
    // Send the data over the socket
    else
    {
        snprintf(command, BUFFER_SIZE, "can,%s,%f", canFrame + 2, stepSize); // to skip "1-"

        sent_bytes = write(new_socket, command, strlen(command));

        if (sent_bytes < 0)
        {
            perror("Error sending data to socket");
            r = 2;
        }
        else
        {
            printf("Sent can command to vECU : %s", command);
        }

    }
    return r;

}

// for test
// int main(void)
// {
//     // 소켓 초기화
//     if (initSocket() != 0)
//     {
//         printf("Socket initialization failed\n");
//         return -1;
//     }

//     printf("Server is listening on port %d...\n", PORT);

//     // CAN 프레임을 받을 버퍼 및 상태 플래그
//     unsigned char canFrame[200] = {0};

//     // SocketToFMI 함수 호출 및 결과 출력
//     while (1)
//     {
//         printf("Waiting for message...\n");
        
//         int result = SocketToFMI(canFrame);

//         if (result == 0)
//         {
//             if (canFrame[0] == '1')
//             {
//                 printf("Received CAN frame: %s\n", canFrame);
//             }
//             else
//             {
//                 printf("No CAN message received, only 'complete'.\n");
//             }
//         }
//         else
//         {
//             printf("Error occurred: %d\n", result);
//             break;
//         }
//     }

//     // 소켓 종료
//     close(new_socket);
//     close(server_fd);
//     return 0;
// }

// for test
// int main(void)
// {
//     // Initialize the socket (dummy function in this example)
//     if (initSocket() != 0)
//     {
//         printf("Socket initialization failed\n");
//         return -1;
//     }

//     printf("Testing FMIToSocket...\n");

//     // Test case 1: Sending CAN frame
//     unsigned char canFrame[] = "1-3-8-11:22:33:44:55:66:77:88";
//     double stepSize = 0.01;
//     int result = FMIToSocket(stepSize, canFrame);
//     if (result == 0)
//     {
//         printf("CAN frame successfully sent.\n");
//     }
//     else
//     {
//         printf("Failed to send CAN frame.\n");
//     }

//     // Test case 2: Sending dostep command
//     unsigned char dostepFrame[] = "0";
//     result = FMIToSocket(stepSize, dostepFrame);
//     if (result == 0)
//     {
//         printf("dostep command successfully sent.\n");
//     }
//     else
//     {
//         printf("Failed to send dostep command.\n");
//     }

//     return 0;
// }