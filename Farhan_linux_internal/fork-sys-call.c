//creation of child process using fork()

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int pid1, pid2;
	
	printf("current proc id %d\n", getpid());	
	
	pid1 = fork();
	
	if(pid1 == 0)
	{
		//child code
		printf("new child pid - %d\n", getpid());
		printf("new child ppid - %d\n", getppid());
		
		sleep(2);
		pid2 = fork();
		
		printf("new child pid 1 - %d\n", getpid());
		printf("new child ppid 1- %d\n", getppid());
	}
	
	else
	{
	
		//parent code
		sleep(3);
		printf("parent pid - %d\n", getpid());
		printf("parent ppid - %d\n", getppid());
		
	}
	
	
	while(1);	//wait--infi loop
	return 0;
}
