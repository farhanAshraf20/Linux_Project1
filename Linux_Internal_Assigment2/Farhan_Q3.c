/*
Q3. A program that replaces old program with new program data and is expected to display
the currently running processes in a hierarchical tree format.
Date : 17-Mar-2022
Farhan Ashraf
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	
	printf("The current process  pid = %d\n", getpid());

	printf("Replacing old program with new data using execl() system call\n");

	execl("/usr/bin/pstree", "pstree", 0);

	printf("Exiting main program\n");

	return 0;
}
