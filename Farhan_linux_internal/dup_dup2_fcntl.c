//duplicate fd creation using dup/dup2

#include<stdio.h>
#include<fcntl.h>


void main()
{
	int fd1, fd2, fd3, fd4;
	
	fd1 = open("linx.txt", O_WRONLY|O_CREAT|O_TRUNC, 0777);
	fd2 = open("linx2.txt", O_WRONLY|O_CREAT|O_TRUNC, 0777);
	
	printf("%d , %d\n", fd1, fd2);
	
	/*
	fd3 = dup(fd1);
	printf("%d\n", fd3);
	
	fd4 = dup2(fd2, 4);		//custom fd
	printf("dup2 - %d\n", fd4);
	*/
	
	/*
	fd4 = dup2(fd2, 4);		//allocate fd ptr on existing fd
	printf("dup2 existing - %d\n", fd4);
	*/
	
	//using fcntl
	
	fd3 = fcntl(fd1, F_DUPFD, 565);
	printf("%d\n", fd3);
	
	//close(fd4);
	close(fd3);
	close(fd2);	
	close(fd1);
}
