#include<stdio.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int fd, child;

	child = fork();
	
	printf("parent process pid is: %d, value of pid is: %d\n",getpid(), child);

	if(child == 0)
	{
		printf("Child process pid: %d\n",getpid());

		execl("/home/farhan/shell/linux1/ass/ass2/Farhan_Q7_1", "./Farhan_Q7_1", 0);//executing a test program using exec()	
	}
	
	else
	{
		int w = wait(0);
		printf("This is parent process with pid = %d\n",getpid());
	}


	return 0;
}

