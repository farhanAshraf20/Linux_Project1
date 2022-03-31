/***********************************************************************************************************
Q2.Write a program where a structure of information passed to pthread task function, and display
structure of information.

Date : 31-Mar-2022
Farhan Ashraf
************************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct f_info
{
	int employ_ID;
	char name[25];
	int salary;
};

void *f_fun_task(void *args)
{
	struct f_info *s = (struct f_info *)args;

	printf("Employ_ID No: %d\nName: %s\nSalary: %d\n",s->employ_ID, s->name, s->salary);

	return NULL;
}

int main()
{
	struct f_info Em;

	pthread_t f_tid;

	Em.employ_ID = 123;
	strcpy(Em.name, "Farhan Ashraf");
	Em.salary = 50000;

	pthread_create(&f_tid, NULL, f_fun_task, &Em);
	pthread_join(f_tid, NULL);

	pthread_exit(NULL);

	return 0;
}