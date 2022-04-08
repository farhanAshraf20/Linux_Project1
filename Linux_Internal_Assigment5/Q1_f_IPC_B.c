/*****************************************************************************************************
Q.1 Write a program that creates a shared memory region and displays shared memory id and also
print address at which shared area in this process starts from.
Date : 08-Apr-2022
Farhan Ashraf
*Write 
***********************************************************************************************************/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#define key 33
int main()
{
    char *f;
    int id;
    
    id = shmget(key,250,IPC_CREAT|0644);              // Shmget function to get the shmid
    
    if(id<0)
    {
        perror("shmget");
        return 0;
    }
    
    printf("id = %d\n", id);
    f = shmat(id,0,0);                             // Shmat function used to write in the data
    printf("Enter the data:");
    scanf("%s", f);
    
    return 0;
}        