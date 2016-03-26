/*
 * Name : list18_2.c
 * Author : Lniper 
 * Date : 2016-03-15
 * Aim : How to use the mask word and set a value.
 */
#include <apue.h>
#include <APUE_ERROR.h>
#include <termios.h>

int main()
{
	struct termios	 term;
	if ((tcgetattr(STDIN_FILENO, &term)) < 0)
		err_sys("tcgetattr error");
	
	switch (term.c_cflag & CSIZE) {
		case CS5:
			printf("5 bits/byte\n");
			break;
		case CS6:
			printf("6 bits/byte\n");
			break;
		case CS7:
			printf("7 bits/byte\n");
			break;
		case CS8:
			printf("8 bits/byte\n");
			break;
		default:
			printf("unknown bits/byte\n");
	}
	
	term.c_cflag &= ~CSIZE;				/* zero out the bits */
	term.c_cflag |= CS8;				/* set 8 bits/byte */
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) < 0)	
		err_sys("tcsetattr error");
		
	exit(0);
}
