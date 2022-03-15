//setting the CFO using file seek (lseek) operation

 #include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main()
{
	
	char Rbuff[50], Wbuff[50] = " hello.......this is write buffer !!!";
	
	int fd1 = open("seek.txt", O_CREAT | O_RDWR, 777);
	
	int len;
	len = write(fd1, Wbuff, 50);
	
	printf("data written = %d\n", len);
	
	lseek(fd1,2, SEEK_SET);
	
	read(fd1, Rbuff, len);
	printf("data read = %s\n",Rbuff);
	
	//lseek(fd1,5, SEEK_END);
	
	read(fd1, Rbuff, len);
	printf("data read = %s\n",Rbuff);
	
	/*lseek(fd1,-10, SEEK_CUR);
	read(fd1, Rbuff, len);
	write(fd1, Wbuff, 50);
	printf("data read = %s\n",Rbuff);*/
	
	
	close(fd1);
	
}
