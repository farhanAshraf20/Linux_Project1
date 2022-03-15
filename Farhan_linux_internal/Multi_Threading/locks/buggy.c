//std cmalloc()

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void buggy()
{
	int *ptr;
	int i;
	ptr = (int *)malloc(sizeof(int)*5);
	
	printf("MALLOC chehcking : addr=%08x, and size=%d\n", ptr, sizeof(int)*5);
	
	for(i=0; i<=19;i++)
	{
		* ptr = i;
		printf("value of ptr %d\n",*ptr);
		ptr++;
	}
}

void main()
{
	buggy();
}
