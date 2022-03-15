//read data in every 3 seconds from /etc/passwd

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>

pthread_t t1, t2;
int fd;

void* th_fn(void *p);




int main(void)
{
	fd = open("/etc/passwd", O_RDONLY);
	//file opened
	
	pthread_create(&t1, NULL, th_fn, "Thread one");
	pthread_create(&t1, NULL, th_fn, "Thread two");
	
	pthread_join(t1, NULL);
	
	pthread_join(t2, NULL);		//pthread_join() has 2 actions to perform------1. joins given thrd-id with main process exec.		2. forces process for completion of thrd ---thrd-id
	
	return 0;
}


void* th_fn(void *p)
{
	char * str, buff[100];
	int n, pid;
	str = (char *)p;
	pid = getpid();
	
	printf("%s : \t started now: \t for process %d \n\n", str, pid);
	
	do
	{
		n = read(fd, buff, 100);
		
		printf("%s : \t read: \t  %d \n\n", str, pid);
		printf("\n----------------------\n");
		
		write(1, buff,n);
		printf("\n----------------------\n");
		sleep(3);
		
	}while(n);
	
	printf("%s : \t finished:  %d \n\n", str, pid);
}



//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	
