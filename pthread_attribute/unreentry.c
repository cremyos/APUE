/*
 * Name : reentry.c
 * Author : Lniper
 * Date : 2016-02-25
 * Aim : The getenv's unreentry.
 */
#include "apue.h"
#include "APUE_ERROR.h"
#include <limits.h>
#include <string.h>

static char envbuf[ARG_MAX];

char *getenv(const char *name)
{
	int i, len;
	
	len = strlen(name);
	for (i = 0; environ[i] != NULL; i++) {
		if ((strncmp(name, environ[i], len) == 0) && (environ[i][len] == '=')) {
			strcpy(envbuf, &environ[i][len+1]);
			return(envbuf);
		}
	}
	return(NULL);
}
