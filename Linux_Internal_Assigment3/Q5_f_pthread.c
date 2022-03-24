/*************************************************************************************************************************
Q5.Write a program that implements threads synchronization using mutex techniques.

operation on global var using mutex lock
this program executes 1 thread at a time

compile "gcc Q5_f_pthread.c -o pth4 -l pthread"

Date : 24-Mar-2022
Farhan Ashraf
*************************************************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


int g_var = 20;		//global variable declared

pthread_mutex_t m_mutex;//creating mutex lock

void* g_inc(void *arg) //increase globalVar by 5
{
	pthread_mutex_lock(&m_mutex); //apply lock
	
	g_var += 5;		//critical section
	
	pthread_mutex_unlock(&m_mutex);	//release lock
	
	printf("increased value = %d\n",g_var);
}

void* g_dec(void *arg) //decrease globalVar by 2
{
	pthread_mutex_lock(&m_mutex); //apply lock
	
	g_var -= 2;		//critical section

	pthread_mutex_unlock(&m_mutex); //release lock
	
	printf("decreased value = %d\n",g_var);
}


void main()
{
	pthread_t t1, t2;
	
	pthread_mutex_init(&m_mutex, NULL);		//initialize mutex lock
	
	pthread_create(&t1, NULL, g_inc, NULL);
	pthread_create(&t2, NULL, g_dec, NULL);
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	printf("global variable is : %d\n", g_var);
	
}