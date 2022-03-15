//threading using global var

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t t1, t2, t3;

int sharedVal = 10;		//global var declared

void* thrd_inc(void *arg)
{
	printf("1st thread in execution\n");
	sharedVal += 22;
	printf("after incrmnt : %d\n", sharedVal);
	
	return NULL;
}

void* thrd_drc(void *arg)
{
	printf("2nd thread in execution\n");
	sharedVal -= 12;
	printf("after decrmnt : %d\n", sharedVal);
	
	return NULL;
}


int main(void)
{
	int ret = pthread_create(&t1, NULL, thrd_inc, NULL);
	int ret2 = pthread_create(&t2, NULL, thrd_drc, NULL);
	//int ret3 = pthread_create(&t3, NULL, func3, NULL);
	
	/*if(ret)
	{
		printf("not created\n");
	}
	
	else
	{
		printf("thread created\n");
	}*/
	
	//sleep(2);		//imp to execute func1			--not suggested for threads
	
	pthread_join(t1, NULL);		//pthread_join() has 2 actions to perform------1. joins given thrd-id with main process exec.		2. forces process for completion of thrd ---thrd-id
	
	pthread_join(t2, NULL);
	//pthread_join(t3, NULL);
	return 0;
}

//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	
