/*
 * Name : list18_4.c
 * Author : Lniper
 * Date : 2016-03-15
 * Aim : Coming ture the isatty function.
 */
#include <termios.h>

int isatty(int fd)
{
	struct termiso	ts;
	return (tcgetattr(fd, &ts) != -1);			/* true if no error (is a tty) */
}
