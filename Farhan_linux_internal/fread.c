#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	
	char buff[50];
	int fd1 = open("new.txt", O_RDWR, 777);
	
	read(fd1, buff,50);
	
	printf("data printed\n");
	write(fd1, buff, 50);
	
	close(fd1);
	
}
