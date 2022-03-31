/***********************************************************************************************
 Q4.write a program, which get and set pthread scheduling policy and priority.
 Date : 31-Mar-2022
 Farhan Ashraf
 * ********************************************************************************************/
#include<stdio.h>
#include<pthread.h>

int main()
{
	pthread_t f_tid;

	struct sched_param f_pr;

	int policy;

	pthread_getschedparam(pthread_self(), &policy, &f_pr);
	printf("Default: \n\npolicy: %d \npriority: %d\n",policy, f_pr.sched_priority);

	policy = SCHED_FIFO;
	f_pr.sched_priority = 4;

	pthread_setschedparam(pthread_self(), policy, &f_pr);

	pthread_getschedparam(pthread_self(), &policy, &f_pr);
	printf("\nAfter Setting: \n\npolicy: %d \npriority: %d\n",policy, f_pr.sched_priority);

	return 0;
}