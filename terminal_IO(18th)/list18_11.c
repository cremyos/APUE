/*
 * Name : list18_11.c
 * Author : Lniper
 * Date : 2016-03-17
 * Aim : Testing the original model and cbreak terminal mode.
 */
#include <apue.h>
#include <APUE_ERROR.h>
#include "list18_10.c"

static void sig_catch(int signo)
{
	printf("signal caught\n");
	tty_reset(STDIN_FILENO);
	exit(0);
}

int main(void)
{
	int		i;
	char	c;
	
	if (signal(SIGINT, sig_catch) == SIG_ERR)	/* catch signals */
		err_sys("signal(SIGINT) error");
	if (signal(SIGQUIT, sig_catch) == SIG_ERR)
		err_sys("signal(SIGINT) error");
	if (signal(SIGTERM, sig_catch) == SIG_ERR)
		err_sys("signal(SIGTERM) error");
	
	if (tty_raw(STDIN_FILENO) < 0)
		err_sys("tty_raw error");
	if (i <= 0)
		err_sys("read error");
	if (tty_cbreak(STDIN_FILENO) < 0)
		err_sys("tty_cbreak error");
	printf("\nEnter raw mode characters, terminate with DELETE\n");
	while ((i = read(STDIN_FILENO, &c, 1)) == 1) {
		c &= 255;
		printf("%o\n", c);
	}
	
	if (tty_reset(STDIN_FILENO) < 0)
		err_sys("tty_reset error");
	if (i <= 0)
		err_sys("read error");
	
	exit(0);
}

