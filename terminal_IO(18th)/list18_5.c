/*
 * Name : list18_5.c
 * Author : Lniper
 * Date : 2016-03-15
 * Aim : Testing isatty function.
 */
#include <apue.h>
#include <APUE_ERROR.h>

int main(void)
{
	printf("fd 0: %s\n", isatty(0) ? "tty" : "not a tty");
	printf("fd 1: %s\n", isatty(1) ? "tty" : "not a tty");
	printf("fd 2: %s\n", isatty(2) ? "tty" : "not a tty");
	exit(0);
}
