/**************************************************************************************************************
Write a program that creates a file with a 4K bytes free space. 
(Such files are called files with holes.)
Date : 11-Mar-2022
Farhan Ashraf
****************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char buf2[]="\0";
int main()
{    
	int fd = creat("file2.txt", 0777);
	
	if (fd < 0) 
	{
		perror("Creation error");
		exit (1);
	}

	if (lseek(fd,4094, SEEK_SET) < 0)
	{
		perror("Positioning error");
		exit(2);
	}
	if (write(fd, buf2, sizeof(buf2)) < 0)
	{	
            perror("Writing error");
            exit(3);
	}
return 0;
}
