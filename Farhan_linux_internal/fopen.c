//file creation in linux--internally		//using creat()

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main()
{
	int fd1 = open("main.c", O_RDONLY, 777);
	printf("%d\n",fd1);
	
	int fd2 = creat("creat-new.txt", 777);
	printf("%d\n",fd2);
	
	int fd3 = creat("creat-new.txt", 777);
	printf("%d\n",fd3);
	
	printf("max size : %d\n", getdtablesize());		//max size of FDs
	close(fd1);
	close(fd2);
	close(fd3);
}
