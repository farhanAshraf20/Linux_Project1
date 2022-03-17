/*
Q5.Write a program, where functions of the program are called in the reverse order of their function calls from main().
Date : 17-Mar-2022
Farhan Ashraf
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int a, b;

void mul()
{
	int result = 0;
	result = a * b;
	printf("multiplication of 2 no's is: %d\n",result);
}

void add()
{ 
	int result = 0;

	result = a + b;
	printf("addition of 2 no's is: %d\n",result);
}

void sub()
{ 
	int result = 0;

	result = a - b;
	printf("difference of 2 no's is: %d\n",result);
}

int main()
{
	printf("Enter two numbers:\n");
	scanf("%d%d",&a, &b);
	
	atexit(mul);
	
	atexit(sub);
	
	atexit(add);
	
	return 0;
	
}
