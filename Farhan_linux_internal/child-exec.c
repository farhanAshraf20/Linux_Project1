//menu driven prog using execl

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
	pid_t pid1;
	int opt, stat;
	
	
	while(1)
	{
		printf("enter 1 to exec 'ls' prog in child process and 0 to exit\n");
		scanf("%d", &opt);
		
		if(!opt)
			exit(0);
		printf("\n");
		
		if(fork()==0)
		{
			execl("/bin/ls", "ls", NULL);
			exit(0);
		}
	}
	
	return 0;
}
