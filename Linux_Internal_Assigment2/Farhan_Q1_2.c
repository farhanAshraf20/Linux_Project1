/*
1.Test whether the process(exec() system call) that replaces old program data , will inherit
the fd's or not.
Date : 17-Mar-2022
Farhan Ashraf
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd;
	
	char buff[200] = "To check if fd inherits or not.";

	fd = open("inherit_fd.txt", O_CREAT|O_RDWR, 0666);
	
	printf("File descriptor = %d\n",fd);

	write(fd, buff, strlen(buff));
	
	close(fd);
	
	return 0;
}
