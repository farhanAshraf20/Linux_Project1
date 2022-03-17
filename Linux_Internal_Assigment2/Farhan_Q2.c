/*************************************************************************************************************************
Q2.Write a program such that parent process create two child processes,such that each child executes a separate task.
Date : 17-Mar-2022
Farhan Ashraf
**************************************************************************************************************************/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int p1, p2;
	
	p1 = fork(); //creating 1st child process
		
	if(p1 == 0)
	{
		//First child executing
		
		printf("\nFirst child in execution\n");
		printf("First child PID - %d\n", getpid());
		printf("Parent PID of First child = %d\n", getppid());
		
		printf("First child executing 'ls -l' command\n");
		execl("/bin/ls", "ls", "-l", NULL);//parent process
	}
	
	
	else
	{
		p2 = fork(); //Second creating child process
	
		if(p2 == 0)
		{
			//Second child executing
			sleep(1);
			printf("\nSecond child in execution\n");
			printf("Second child PID - %d\n", getpid());
			printf("Parent PID of Second child - %d\n", getppid());
			printf("Second child creating file_Q2.txt\n");
			execl("/bin/touch", "touch", "file_Q2.txt",NULL);	
		}
		
		else
		{
			//parent process executing
			sleep(3);
			printf("\nparent process executing\n");
			printf("parent PID - %d\n", getpid());
		}
		
	}
	
	return 0;
}
