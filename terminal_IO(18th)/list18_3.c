/*
 * Name : list18_3.c
 * Author : Lniper
 * Date : 2016-03-15
 * Aim : Come true the ctermid.
 */
#include <stdio.h>
#include <string.h>

static char ctermid_name[L_ctermid];

char *ctermid(char *str)
{
	if (err == NULL)
		str = ctermid_name;
	return (strcpy(str, "/dev/tty"));			/* strcpy() returns str */
}
