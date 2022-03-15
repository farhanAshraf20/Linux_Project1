//op on global var using mutex lock
//this program executes 1 thread at a time


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int sharedVal = 5;

pthread_mutex_t my_mutex;			//creating mutex lock

void *td_inc(void *arg)
{
	pthread_mutex_lock(&my_mutex);		//apply lock
	sharedVal++;		//critical section
	pthread_mutex_unlock(&my_mutex);		//release lock
	
	printf("inc val = %d\n",sharedVal);
}


void *td_dec(void *arg)
{
	pthread_mutex_lock(&my_mutex);		//apply lock
	sharedVal--;		//critical section
	pthread_mutex_unlock(&my_mutex);		//release lock
	
	printf("dec val = %d\n",sharedVal);
}


void main()
{
	pthread_t th1, th2;
	
	pthread_mutex_init(&my_mutex, NULL);		//initialize mutex lock
	
	pthread_create(&th1, NULL, td_inc, NULL);
	pthread_create(&th2, NULL, td_dec, NULL);
	
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);

	printf("sharedVal is %d\n", sharedVal);
	
}
