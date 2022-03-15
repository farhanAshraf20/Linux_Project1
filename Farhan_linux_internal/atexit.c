#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void func1()
{
	printf("this is func1\n");
}

void func2()
{
	printf("this is func2\n");
}

void func3()
{
	printf("this is func3\n");
}

int main()
{
	//printf("func1\n");
	atexit(func1);
	//printf("func2\n");
	atexit(func2);
	//printf("func3\n");
	atexit(func3);
	
	
	
	//while(1);	//wait--infi loop
	
	//_exit(0);		//will not call for the func which are registred at atexit()
	
	return 0;
	
}
