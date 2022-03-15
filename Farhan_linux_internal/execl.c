//use of execl() 

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int pid1, pid2;
	
	printf("executing ls\n");	
	
	pid1 = fork();
	
	execl("/usr/bin/vim", "vim", "info.txt", 0);
	
	printf("exec ls\n");
	printf("exec ls\n");
	printf("exec ls\n");
	
	
	//while(1);	//wait--infi loop
	return 0;
}
