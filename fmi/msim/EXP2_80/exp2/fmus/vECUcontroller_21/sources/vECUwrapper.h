#ifndef _VECUWRAPPER_H_
#define _VECUWRAPPER_H_

int initSocket(int portNumber, int fmuNum);
void deinitSocket(void);

int SocketToFMI(unsigned char *canFrame, int fmuNum);
int FMIToSocket(double stepSize, const unsigned char *canFrame, int fmuNum);

#endif

