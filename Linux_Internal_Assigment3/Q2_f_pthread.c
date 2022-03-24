/*************************************************************************************************************************
Q2.Write a program where thread cancel itself.(use pthread_cancel())

compile " gcc Q2_f_pthread.c -o pth1 -l pthread"

Date : 24-Mar-2022
Farhan Ashraf
*************************************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* c_thr(void *t_id)
{
	printf("\nc_thr() function called by thread_id 't1' in execution.\n");
	while(1);		//infinite loop
}

int main()
{
	pthread_t t1;
	
	printf("creating thread\n");
	
	pthread_create(&t1, NULL, c_thr, NULL); //creating thread and assigning it c_thr() to execute
	
	printf("thread id %ld\n", t1);
		
	sleep(5); //sleep for 5 sec till then thread will execute
	
	printf("Cancelling thread.\n");
	
	pthread_cancel(t1);
	
	printf("Thread cancelled.\n");
	
	return 0;
}