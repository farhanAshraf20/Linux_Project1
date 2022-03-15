//use of pthread_cancel(self)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>



void* func1(void *thrdId)
{
	printf("hello from thrd\n");
	while(1);
}


int main(void)
{
	pthread_t t1;
	
	printf("creating thread\n");
	int ret = pthread_create(&t1, NULL, func1, NULL);
	
	printf("thrd id %u\n", ret);
		
	sleep(6);
	int t = pthread_cancel(ret);
	
	return 0;
}

//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	
