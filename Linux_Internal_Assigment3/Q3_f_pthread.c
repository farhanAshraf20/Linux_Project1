/*************************************************************************************************************************
Q3.Write a program that changes the default properties of newly created posix threads.
(ex: to change default pthread stack size )

compile "gcc Q3_f_pthread.c -o pth2 -l pthread"

Date : 24-Mar-2022
Farhan Ashraf
*************************************************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>


void* f_fun(void *param)
{
	printf("pthread creation using user attributes\n");
	sleep(3);
	return NULL;
}

int main(void)
{
	pthread_attr_t m_attr;
	pthread_t t1;
	
	void *stck;
	size_t s;
	int err;
	
	size_t m_size = 5000;
	void * m_stack;
	
	pthread_attr_init(&m_attr);			//init attribute
	pthread_attr_getstacksize(&m_attr, &s);	//get size of stack
	pthread_attr_getstackaddr(&m_attr, &stck);	//get stack address
	
	printf("default address of stack : %08x default size of stack : %d\n", stck, s);
	
	m_stack = (void*)malloc(m_size);		//define a new stack with attributes of our choice
	
	pthread_attr_setstack(&m_attr, m_stack, m_size);			//set stack
	
	pthread_create(&t1, &m_attr, f_fun, NULL);
	
	
	pthread_attr_getstack(&m_attr, &stck, &s);			//get info of new stack
	
	printf("\ndefault address of stack : %08x default size of stack : %d\n", stck, s);
	
	return 0;
}