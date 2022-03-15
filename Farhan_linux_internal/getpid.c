//using getpid() to get current process id

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	printf("my pid is %d\n", getpid());	//curr pid--of calling process
	printf("my ppid is %d\n", getppid());	//parent pid
	
	printf("linux kernel\n");
	
	while(1);	//wait--infi loop
	return 0;
}
