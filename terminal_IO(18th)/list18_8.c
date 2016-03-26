/*
 * Name : list18_8.c
 * Author : Lniper
 * Date : 2016-03-16
 * Aim : Coming ture the getpass function.
 */
#include <signal.h>
#include <stdio.h>
#include <termios.h>

#define MAX_PASS_LEN	8 /* max #chars for user to enter */

char *getpass(const char *prompt)
{
	static char 	buf[MAX_PASS_LEN + 1];			/* null byte at enter*/
	char 			*ptr;
	sigset_t		sig, osig;
	struct termios	ts, ots;
	FILE			*fp;
	int 			c;
	
	if ((fp = fopen(ctermid(NULL), "r+")) == NULL)
		return(NULL);
	setbuf(fp, NULL);
	
	sigemptyset(&sig);
	sigaddset(&sig, SIGINT);			/* block SIGINT */
	sigaddset(&sig, SIGTSTP);			/* block SIGTSTP */
	sigprocmask(SIG_BLCK, &sig, &osig);	/* and save mask */

	tcgetattr(fileno(fp), &ts);			/* save tty state */
	ots = ts;							/* structure copy */
	ts.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL);
	tcsetattr(fileno(fp), TCSAFLUSH, &ts);
	fputs(prompt, fp);
	
	ptr = buf;
	while ((c = getc(fp)) != EOF && c != '\n')
		if (ptr < &buf[MAX_PASS_LEN])
			*ptr++ = c;
	*ptr = 0;					/* null terminate */
	putc('\n', fp);				/* we echo a newline */
	
	tcsetattr(fileno(fp), TCSAFLUSH, &ots);			/* restore TTY state */
	sigprocmask(SIG_SETMASK, &osig, NULL);			/* restore mask */
	fclose(fp);					/* done with /dev/tty */
	return(buf);
}
