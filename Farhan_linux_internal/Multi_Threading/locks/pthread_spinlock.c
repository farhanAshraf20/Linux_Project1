//spin lock and thread creation

#define _XOPEN_SOURCE 600
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t spinlock;

volatile int slock;



void *spin_td(void *i)
{
	int rc, count=0;
	
	printf("entered thread = %d , getting spin lock \n", (int *)i);
	
	rc = pthread_spin_lock(&spinlock);
	
	printf("%d thread unlock the spin lock \n", (int *)i);
	
	return NULL;
}


void main()
{
	pthread_t th1, th2;
	int rc;
	
	if(pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE) != 0)
		perror("init");
		
	printf("main, get spin lock\n");
	
	rc = pthread_spin_lock(&spinlock);
	printf("main, create spin lock thread\n");
	rc = pthread_create(&th1, NULL, spin_td, (int *)1);
	
	printf("main, wait a bit holding the spin\n");
	sleep(10);
	rc = pthread_spin_unlock(&spinlock);
	
	if(rc == 0)
	{
		printf("main, unlocked successfully!!\n");
	}	
	
	else
	{
		printf("main,  unsuccessfully unlocked !!\n");
	}
	
	printf("main,  wait for thread to end \n");
	
	pthread_join(th1, NULL);
	
	printf("main,  complete\n");
}
