/**********************************************************************************************************************************
File operations program that demonstrates copying of data from input file and write into output file, until reaches end of file data.
Date : 11-Mar-2022
Farhan Ashraf
*********************************************************************************************************************************/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main()
{
	
	char Rbuff[1000];
	
	int fd1 = open("input.txt", O_RDONLY, 777);    //open input file (to be created before execution)
	int fd2 = open("output.txt",O_CREAT | O_RDWR, 777);     //open output file (blank file to be created before execution) 
        //please give write permission for output file ( chmod +w output.txt )

	int len;
	
	read(fd1, Rbuff, 200);   //reading from input.txt
	printf("data read = %s\n",Rbuff);


	len = write(fd2, Rbuff, 200);    //writing to output.txt
	printf("data written = %d \n", len);
	
	
	
	close(fd2);
	close(fd1);
	
}
