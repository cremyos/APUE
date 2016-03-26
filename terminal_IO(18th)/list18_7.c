/*
 * Name : list18_7.c
 * Author : Lniper
 * Date : 2016-03-16
 * Aim : Testing ttyname function.
 */
#include <apue.h>
#include <APUE_ERROR.h>

int main(void)
{
	char *name;
	
	if (isatty(0)) {
		name = ttyname(0);
		if (name == NULL)
			name = "undefined";
	} else {
		name = " not a tty";
	}
	printf("fd 0: %s\n", name);
	if (isatty(1)) {
		name = ttyname(1);
		if (name == NULL)
			name = "underfined";
	} else {
		name = "not a tty";
	}
	printf("fd 1: %s\n", name);
	if (isatty(2)) {
		name = ttyname(2);
		if (name == NULL)
			name = "undefined";
	} else {
		name = "not a tty";
	}
	printf("fd 2: %s\n", name);
	exit(0);
}
