/*************************************************************************************************************************
Q4.Write a program where pthread task displays the thread id and also prints the calling process pid. 

compile "gcc Q4_f_pthread.c -o pth3 -l pthread"

Date : 24-Mar-2022
Farhan Ashraf
*************************************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/types.h>

pthread_t t1;

void* f_fun(void *arg)
{
	printf("\nnewly created thread in execution\n");
	printf("pthread id : %lu\nCalling Process id : %d\n", pthread_self(), getpid());
	
	return NULL;
}


int main(void)
{
	int s;
	
	s = pthread_create(&t1, NULL, f_fun, NULL);			//thread creation
	
	if(s)
	{
		printf("not created\n");
	}
	
	else
	{
		printf("thread created\n");
		
	}
	
	pthread_join(t1, NULL);
	
	printf("\nExiting main process\n");
	
	return 0;
}