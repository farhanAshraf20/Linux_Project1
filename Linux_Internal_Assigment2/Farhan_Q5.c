/****************************************************************************************************************************
Q5.Write a program, where functions of the program are called in the reverse order of their function calls from main().
Date : 17-Mar-2022
Farhan Ashraf
****************************************************************************************************************************/
#include  <stdio.h>
#include  <fcntl.h>
#include  <unistd.h>
#include  <sys/types.h>

void  main()
{
	pid_t  pid;  // pid_t data type is a signed integer type which is capable of representing a process ID

	pid = fork();
 
	if (pid == 0) 
	{
		int fd;
		char buff[500];

		printf("Child process pid : %d\n",getpid());

		fd = open("file1_Q5.txt",O_RDONLY,0777);
		printf("value of fd : %d\n",fd);

		printf("write data into buffer from file\n");
		read(fd,buff,sizeof(buff));
		
		printf("\nData take form file is = %s\n",buff);
	}
	else
	{ 
		sleep(2);
		printf("Parent process pid : %d\n",getpid());
	}
}

