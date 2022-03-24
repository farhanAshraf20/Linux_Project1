/*************************************************************************************************************************
Q1.Write a multithreading program, where threads runs same shared golbal variable of the process between them.

compile " gcc f_pthread.c -o pth -l pthread "

Date : 24-Mar-2022
Farhan Ashraf
*************************************************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t t1, t2;		//variables to store thread id

int g_var = 10;		//global variable declared

void* g_inc(void *arg) //increase globalvar by 15
{
	printf("1st thread in execution\n");
	g_var += 15;
	printf("after increment : %d\n", g_var);
	return NULL;
}

void* g_dec(void *arg) //decrease globalvar by 5
{
	printf("2nd thread in execution\n");
	g_var -= 5;
	printf("after decrement : %d\n", g_var);
	return NULL;
}


int main()
{
	pthread_create(&t1, NULL, g_inc, NULL);
	pthread_create(&t2, NULL, g_dec, NULL);
	
	//executing threads
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	//returning to parent process
	printf("\nExecuting parent process\n");
	
	return 0;
}