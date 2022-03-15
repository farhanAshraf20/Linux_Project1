//creating child process and running 'ls' on that using excel()

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	int pid1, pid2;
	
	printf("executing wait\n");	
	
	pid1 = fork();
	
	
	if(pid1 == 0)
	{
		//child code
		sleep(5);
		printf("new child pid - %d\n", getpid());
		//printf("new child ppid - %d\n", getppid());
		
		execl("/bin/ls", "ls" , NULL);		
	}
	
	else
	{
	
		//parent code
		//sleep(3);
		int pid2;
		printf("parent pid - %d\n", getpid());
		//printf("parent ppid - %d\n", getppid());
		pid2=wait(0);
		
		printf("pid2 - %d\n", pid2);
		printf("parent pid - %d\n", getpid());
	}
	
	//while(1);	//wait--infi loop
	return 0;
}
