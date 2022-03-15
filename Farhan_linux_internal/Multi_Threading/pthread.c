#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t tid;

void* func1(void *arg)
{
	printf("newly created thread in execution\n");
	return NULL;
}


int main(void)
{
	int ret = pthread_create(&tid, NULL, func1, NULL);
	
	if(ret)
	{
		printf("not created\n");
	}
	
	else
	{
		printf("thread created\n");
	}
	
	//sleep(2);		//imp to execute func1			--not suggested for threads
	
	pthread_join(tid, NULL);		//pthread_join() has 2 actions to perform------1. joins given thrd-id with main process exec.		2. forces process for completion of thrd ---thrd-id
	
	return 0;
}

//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	
