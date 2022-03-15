#include<stdio.h>
#include<pthread.h>


#define NUM_THREADS 3


int i;


void *func(void *arg)
{
i++;
int result =0;


result = result+i*1000;


printf("Result : %d\n",result);


pthread_exit(NULL);
}


int main()
{
pthread_t thread[NUM_THREADS];
pthread_attr_t attr;


int rc, t, status, detach_state;


/* Initialize and */
pthread_attr_init(&attr);


pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

for(int i=0; i <NUM_THREADS; i++)
{
printf("Thread: %d\n",i);
pthread_create(&thread[i], NULL, func, NULL);

}

//gets default set by us
pthread_attr_getdetachstate(&attr, &detach_state);
printf("\ndetach state: %d\n",(int *)detach_state);

printf("exiting from main thread\n");

pthread_exit(NULL);



return 0;
}
