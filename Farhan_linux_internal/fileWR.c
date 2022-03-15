//creating, reading and writing a file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	
	char Rbuff[50], Wbuff[] = " hello.......this is write buffer !!!";
	int fd1 = open("read-write.txt", O_CREAT | O_RDWR, 777);
	
	int len;
	len = write(fd1, Wbuff, 50);
	
	printf("data written = %d \n", len);
	
	read(fd1, Rbuff, len);
	
	printf("data read = %s\n",Rbuff);
	
	
	close(fd1);
	
}
