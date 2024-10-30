#ifndef _VECUWRAPPER_H_
#define _VECUWRAPPER_H_

int initSocket(int PortNumber);
void deinitSocket(void);

int SocketToFMI(unsigned char *canFrame);
int FMIToSocket(double stepSize, unsigned char *canFrame);

#endif

