//creating child process using fork and using it to execute a program using execl 

//changes to be done	-- code contains some errors


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int pid1, pid2;
	
	printf("executing ls\n");	
	
	pid1 = fork();
	
	
	if(pid1 == 0)
	{
		//child code
		printf("new child pid - %d\n", getpid());
		printf("new child ppid - %d\n", getppid());
		
		execl("/home/ubuntu/Linux_internals/exectest_cmd_line.c", "./exct" "linux", "kernel" , 0);		
	}
	
	else
	{
	
		//parent code
		sleep(3);
		printf("parent pid - %d\n", getpid());
		printf("parent ppid - %d\n", getppid());
		
	}
	
	//while(1);	//wait--infi loop
	return 0;
}
