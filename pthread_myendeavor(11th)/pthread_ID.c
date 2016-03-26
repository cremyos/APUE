/*
 *Name : pthread_ID.c
 *Author : Lniper
 *Date : 2016-02-16
 *Aim : Printting the pthread ID.
 */
#include "apue.h"
#include "APUE_ERROR.h"
#include <pthread.h>

pthread_t ntid;

void printids(const char *s)
{
	pid_t pid;
	pthread_t tid;
	
	pid = getpid();
	tid = pthread_self();			//get the pthread self ID
	printf("%s pid %u tid %u (0x%x)\n",s,(unsigned int)pid,(unsigned int)tid,(unsigned int)tid);
}

void *thr_fn(void *arg)
{
	printids("new thread: ");
	return ((void *)0);
}

int main(void)
{
	int err;

	err=pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err!=0)
		err_quit("Can't create thread: %s\n",strerror(err));
		//printf("ERROR!\n");
	printids("main thread:");
	sleep(1);
	//exit(0);
	return 0;
}


