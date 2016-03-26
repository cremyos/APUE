/*
 * Name : list18_9.c
 * Author : lniper
 * Date : 2016-03-16
 * Aim : Using getpass function. 
 */
#include <apue.h>
#include <APUE_ERROR.h>

char *getpass(const char *);

int main(void)
{
	char	*ptr;
	
	if ((ptr = getpass("Enter password:")) == NULL)
		err_sys("getpass error");
	printf("password: %s\n", ptr);

	/* now use password (probably encrypt it) ... */
	
	while (*ptr != 0)
		*ptr++ = 0;			/* zero it out when we're done with it */
	exit(0);
}
