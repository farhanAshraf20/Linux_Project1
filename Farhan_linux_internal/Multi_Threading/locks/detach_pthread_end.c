
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

void * process(void *arg)
{
	/*detach self.*/
	
	pthread_detach(pthread_self());		//detach resources automatically
	
	printf("sleeping for 2sec\n");
	
	sleep(2);
	
	printf("process woked up\n");
}



void main()
{
	pthread_t th, th2;
	
	pthread_create(&th2, NULL, process, NULL);
	
	pthread_exit(NULL);			//end process but not the program
	
	
	
}
