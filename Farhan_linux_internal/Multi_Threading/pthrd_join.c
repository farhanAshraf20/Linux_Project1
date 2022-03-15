//thread join

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t t1, t2, t3;

void* func1(void *arg)
{
	//int i =19;
	printf("1st thread in execution\n");
	return NULL;
}

void* func2(void *arg)
{
	printf("2nd thread in execution\n");
	return NULL;
}

void* func3(void *arg)
{
	printf("3rd thread in execution\n");
	return NULL;
}

int main(void)
{
	int ret = pthread_create(&t1, NULL, func1, NULL);
	int ret2 = pthread_create(&t2, NULL, func2, NULL);
	int ret3 = pthread_create(&t3, NULL, func3, NULL);
	
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
	
	pthread_join(t2, NULL);			//in place of NULL----returned value of function can be there
	pthread_join(t3, NULL);
	return 0;
}

//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	
