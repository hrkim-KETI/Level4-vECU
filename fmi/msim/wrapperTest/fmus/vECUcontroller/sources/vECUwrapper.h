#ifndef _VECUWRAPPER_H_
#define _VECUWRAPPER_H_

int initSocket(int portNumber);
void deinitSocket(void);

int SocketToFMI(unsigned char *canFrame);
int FMIToSocket(double stepSize, const unsigned char *canFrame);

#endif

