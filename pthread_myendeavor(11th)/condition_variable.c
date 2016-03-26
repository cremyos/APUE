/*
 *Name : condition_variable.c
 *Author : Lniper 
 *Date : 2016-02-17
 *Aim : The condition variable and mutex make the thread synchronization.
 */
#include <pthread.h>
struct msg{
	struct msg *m_next;
	/* ... more stuff here ... */
};

structy msg *workq;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg(void)
{
	struct msg *mp;
	
	for (;;) {
		pthread_mutex_lock(&qlock);
		while (workq = NULL)
			pthread_cond_wait(&qready, &qlock);
		mp = workq;
		workq = mp->m_next;
		pthread_mutex_unlock(&qlock);
		/* new process the message mp */
	}
}
	
void enqueue_msg(struct msg *mp)
{
	pthread_mutex_lock(&qlock);
	mp->m_next = workq;
	workq = mp;
	pthread_mutex_unlock(&qlock);
	pthread_cond_signal(&qready);
}
