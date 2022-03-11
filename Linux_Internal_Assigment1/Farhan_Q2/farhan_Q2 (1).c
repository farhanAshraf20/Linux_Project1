/*******************************************************************************************************
Write a program that demonstrates repositioning of file offset using SEEK_SET, SEEK_END and SEEK_END.
Date : 11-Mar-2022
Farhan Ashraf
*********************************************************************************************************/

#include<stdio.h>
#include<fcntl.h>

int main()
{

int fd1, fd2, fd3;
int len=0;

char w_buff[] = "This is Writing data to write.txt file to both read and write operation\n";

fd1 = open("write.txt", O_CREAT | O_RDWR, 0666);
len=write(fd1 , w_buff, sizeof(w_buff));
printf("File descriptor returned by fd1 is: %d and data written length is: %d\n",fd1,len);

lseek(fd1, 0, SEEK_SET);

char r_buff[len];

read(fd1, r_buff, len);
// printf("File descriptor returned by fd1 is: %d\n",fd1);
printf("File contents are: %s",r_buff);
close(fd1);

int l=0;
char buf[]="Here I am using the concept of lseek and it's flags: SEEK_SET, SEEK_CUR, SEEK_END";
int curr=0;

curr = lseek(fd1, 0, SEEK_CUR);
printf("Current position of file is: %d\n",curr);

fd2 = open("write.txt", O_RDWR, 0666);
lseek(fd2, 0, SEEK_END);

l = write(fd2 , buf, sizeof(buf));
printf("File descriptor returned by fd2 is: %d and data written length is: %d\n",fd1,l);

lseek(fd2, len, SEEK_SET);
char buf1[l];

read(fd2, buf1, l);
// printf("File descriptor returned by fd1 is: %d\n",fd1);
printf("File contents are: %s",buf1);

close(fd2);

return 0;
}
