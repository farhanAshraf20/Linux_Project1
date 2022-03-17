/*
Q4.A processs using execl() system call should replace a new command line program.
Date : 17-Mar-2022
Farhan Ashraf
*/
#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("program to replace command line program\n\nDisplaying present working directory\n");

	execl("/bin/pwd", "pwd", 0);

	return 0;
}
