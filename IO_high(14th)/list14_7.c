/*
 * Name : list14_7.c
 * Author : Lniper 
 * Date : 2016-03-12
 * Aim : Checking the description quto the STREAMS device.
 */
#include <stropts.h>
#include <unistd.h>

int isastream(int fd)
{
	return (ioctl(fd, I_CANPUT, 0) != -1);
}


