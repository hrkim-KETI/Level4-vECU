//
// Copyright (c) 2010-2024 Antmicro
// Copyright (c) 2011-2015 Realtime Embedded
//
// This file is licensed under the MIT License.
// Full license text is available in 'licenses/MIT.txt'.
//
using System;
using System.IO;
using System.Net.Sockets;
using System.Text;
using Antmicro.Renode.Time;
using Antmicro.Renode.Exceptions;
using Antmicro.Renode.UserInterface;
using Antmicro.Renode.UserInterface.Commands;  // IncludeFileCommand를 위해 추가
using Antmicro.Renode.UserInterface.Tokenizer; // StringToken을 위해 추가
using System.Collections.Generic;
using Antmicro.Renode.Core.CAN;
using AntShell.Commands;
using System.Linq;
using Antmicro.Renode.Logging;

namespace Antmicro.Renode.Core
{
    public class FMIHandler
    {
        // hrkim
        private static TcpClient client;
        private static NetworkStream stream;
        public static Queue<CANMessageFrame> txMessageBufferFMI = new Queue<CANMessageFrame>();
        // public static Queue<CANMessageFrame> rxMessageBufferFMI = new Queue<CANMessageFrame>();
        public static event Action<CANMessageFrame> OnCANFrameReceived;


        public static void ConnectToServer(string serverIp, int port)
        {
            try
            {
                client = new TcpClient();
                client.Connect(serverIp, port);  // 서버에 연결
                stream = client.GetStream();
                Console.WriteLine($"Connected to server at {serverIp}:{port}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Could not connect to server: {ex.Message}");
            }
        }

        public static void DisconnectFromServer()
        {
            stream?.Close();
            client?.Close();
            Console.WriteLine("Disconnected from server.");
        }

        public static void SendCompletionMessageToServer()
        {
            if (stream != null && stream.CanWrite)
            {
                string completionMessage = "complete";

                string canMessage = string.Empty;

                lock(txMessageBufferFMI)
                {
                    if (txMessageBufferFMI.Count > 0)
                    {
                        var message = txMessageBufferFMI.Dequeue();
                        var formattedMessage = $"can,1-{message.Id.ToString()}-0-{message.Data.Length.ToString()}-{BitConverter.ToString(message.Data).Replace("-", ":")}";
                        canMessage += $",{formattedMessage}";
                        completionMessage += canMessage;
                    }
                }

                byte[] messageBuffer = Encoding.ASCII.GetBytes(completionMessage);
                stream.Write(messageBuffer, 0, messageBuffer.Length);
                Console.WriteLine($"Sent completion message to server: {completionMessage}");
            }
            else
            {
                Console.WriteLine("Stream is not available for writing.");
            }
        }

        // ReceiveCommand waits for incoming data from the vECU Controller.
        public static string ReceiveCommand()
        {
            if (stream == null || !stream.CanRead)
            {
                Console.WriteLine("Stream not available to receive data.");
                return null;
            }

            byte[] buffer = new byte[256]; // Buffer to hold incoming command data
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            if (bytesRead > 0)
            {
                // Convert bytes to string command
                string command = Encoding.ASCII.GetString(buffer, 0, bytesRead);
                Console.WriteLine($"Received command: {command}");
                return command;
            }
            return null;
        }
        // HandleCommand processes the received command and executes appropriate actions.
        public static void HandleCommand(string command, Antmicro.Renode.UserInterface.Monitor monitor, string rescPath)
        {
            if (string.IsNullOrEmpty(command))
            {
                Console.WriteLine("No command to process.");
                return;
            }

            // Split command into components (command type and parameters)
            var commandParts = command.Split(',');
            var commandType = commandParts[0].Trim(); // first part is command type

            // Handle different command types and parameters
            switch (commandType)
            {
                case "init":
                    if (!string.IsNullOrEmpty(rescPath))
                    {
                        // var rescFilePath = commandParts[1].Trim(); // Second part is the rescPath file path
                        var includeCommand = $"include @{rescPath}";
                        IncludeRescFile(includeCommand, monitor);
                        Console.WriteLine($"Initializing simulation with resc file: {rescPath}");
                        monitor.Parse("currentTime");
                    }
                    else
                    {
                        Console.WriteLine("No resc file path provided.");
                    }
                    break;

                case "dostep":
                    // Expecting format like: doStep, "0.01" (10ms)
                    if (commandParts.Length > 1)
                    {
                        var period = commandParts[1].Trim();  
                        // Console.WriteLine($"Executing runfor {period}");
                        TimeInterval parsedPeriod;

                        // Parsing to TimeInterval and Execute RunFor
                        if (TimeInterval.TryParse(period, out parsedPeriod))
                        {
                            try
                            {
                                EmulationManager.Instance.CurrentEmulation.RunFor(parsedPeriod);
                                Console.WriteLine("dostep completed successfully.");
                                monitor.Parse("currentTime");

                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine($"Error during emulation: {ex.Message}");
                            }
                        }
                        else
                        {
                            Console.WriteLine($"Invalid time format: {period}");
                        }
                    }
                    else
                    {
                        Console.WriteLine("No step size provided.");
                    }
                    break;

                case "can":
                    if (commandParts.Length > 2) // "can", "canmessage", "period"
                    {
                        var canMessage = commandParts[1].Trim(); // sof-id-fd-dlc-data
                        var period = commandParts[2].Trim();
                        TimeInterval parsedPeriod;

                        
                        var messageParts = canMessage.Split('-');
                        if (messageParts.Length == 5)
                        {
                            // var dlc = messageParts[0].Trim();           // sof
                            var canMessageId = messageParts[1].Trim();     // id
                            // var dlc = messageParts[2].Trim();           // fd
                            // var dlc = messageParts[3].Trim();           // dlc
                            var canMessageData = messageParts[4].Trim();
                            
                            // this.Log(LogLevel.Debug, $"hrkim-Processing CAN message with ID: {canMessageId}, Data: {canMessageData}");
                            
                            var rxCANMessage = ProcessCANMessage(canMessageId, canMessageData);
                            Console.WriteLine($"hrkim-rxCANMessage in can command: {rxCANMessage}");

                            OnCANFrameReceived?.Invoke(rxCANMessage);
                            
                        }

                        if (TimeInterval.TryParse(period, out parsedPeriod))
                        {
                            try
                            {
                                EmulationManager.Instance.CurrentEmulation.RunFor(parsedPeriod);
                                // hrkim : for test
                                monitor.Parse("currentTime");
                                Console.WriteLine("can completed successfully.");
                            }
                            catch (Exception ex)
                            {
                                Console.WriteLine($"Error during emulation: {ex.Message}");
                                // this.Log(LogLevel.Warning, $"Error during emulation: {ex.Message}");

                            }
                        }
                        else
                        {
                            Console.WriteLine($"Invalid time format: {period}");
                            // this.Log(LogLevel.Debug, $"Invalid time format: {period}");

                        }
                    }
                    else
                    {
                        Console.WriteLine("Invalid CAN commnad format.");
                        // this.Log(LogLevel.Debug, "Invalid CAN commnad format.");

                    }
                    break;

                case "quit":
                    try
                    {
                        monitor.Parse("currentTime");
                        // EmulationManager.Instance.CurrentEmulation.Dispose();
                        Console.WriteLine("Emulation is quitted successfully.");
                    }
                    catch (Exception ex)
                    {
                        Console.WriteLine($"Error during quit: {ex.Message}");
                    }
                    break;

                default:
                    Console.WriteLine($"Unknown command: {commandType}");
                    break;
            }
        }

        // hrkim : convert array with ':' to data bytes
        private static CANMessageFrame ProcessCANMessage(string id, string data)
        {
            try
            {
                var messageID = Convert.ToUInt32(id, 10);   // ID conversion with hex
                // var dataLength = Convert.ToByte(dlc);       // DLC conversion with byte
                var dataBytes = data.Split(':').Select(b => Convert.ToByte(b, 16)).ToArray();

                var canMessageFrame = new CANMessageFrame(messageID, dataBytes);
                return canMessageFrame;

            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error processing CAN message: {ex.Message}");
                return null;
            }
        }

        // Method to parse and include resc file without Monitor shell interaction
        private static void IncludeRescFile(string rescFilePath, Antmicro.Renode.UserInterface.Monitor monitor)
        {
            // Console.WriteLine($"rescFile : {rescFilePath}");
            try
            {
                monitor.Parse(rescFilePath);
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error loading resc file: {ex.Message}");
            }
        }
    }
}


