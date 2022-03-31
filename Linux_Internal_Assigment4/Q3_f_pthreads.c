/***********************************************************************************************
 Q3.Write a pthread program that implements simple initialization code.
 Date : 31-Mar-2022
 Farhan Ashraf
 **********************************************************************************************/

#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_once_t once_code = PTHREAD_ONCE_INIT;

void *f_int()
{
	printf("initialization code\n");
}

void *f_th_task(void *args)
{
	printf("In thread %d\n",(int *)args);
	
	pthread_once(&once_code , (void *)f_int);

	printf("Exiting thread %d\n", (int *)args);

	return NULL;
}

int main()
{
	pthread_t f_th_id1, f_th_id2, f_th_id3;

	pthread_create(&f_th_id1, NULL, f_th_task, (void *)1);
	pthread_create(&f_th_id2, NULL, f_th_task, (void *)2);
	pthread_create(&f_th_id3, NULL, f_th_task, (void *)3);

	pthread_join(f_th_id1, NULL);
	pthread_join(f_th_id2, NULL);
	pthread_join(f_th_id3, NULL);

	return 0;
}