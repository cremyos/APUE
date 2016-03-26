/*
 *Name : pthread_mutex.c
 *Author : Lniper
 *Date : 2016-02-17
 *Aim : Using the mutex to protect the data struct.
 */
#include <stdlib.h>
#include <pthread.h>

struct foo{
	int f_count;
	pthread_mutex_t f_lock;
};

struct foo *foo_alloc(void)
{
	/* allocate the object */
	struct foo *fp;
	
	if((fp = malloc(sizeof(struct foo))) != NULL){
		fp->f_count = 1;
		if(pthread_mutex_init(&fp->f_lock, NULL) != 0){
			free(fp);
			return(NULL);
		}
		/* ...continue initialization ... */
	}
	return (fp);
}

void foo_hold(strcut foo *fp)
{
	/* add a reference to the object */
	pthread_mutex_lock(&fp->f_lock);
	fp->f_count++;
	pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo *fp)
{
	/* release a reference to the object */
	pthread_mutex_lock(&fp->f_lock);
	if(--fp->f_count == 0){/* last reference */
		pthread_mutex_unlock(&fp->f_lock);
		pthread_mutex_destory(&fp->f_lock);
		free(fp);
	}
	else{
		pthread_mutex_unlock(&fp->f_lock);
	}
}