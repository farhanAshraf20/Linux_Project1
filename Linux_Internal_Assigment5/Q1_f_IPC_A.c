/*****************************************************************************************************
Q.1 Write a program that creates a shared memory region and displays shared memory id and also
print address at which shared area in this process starts from.
Date : 08-Apr-2022
Farhan Ashraf

***********************************************************************************************************/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>

#define key 33

int main()
{
    char *f;
    int id;
    
    id = shmget(key,250,IPC_CREAT|0644);               // Creating the shared memeory id
    
    if(id < 0)
    {
        perror("shmget\n");
        return 0;
    }
    
    printf("id = %d\n", id);
    
    
    f = shmat(id,0,0);                      // Returning an shmat value 'f' to get the id and address
    
    printf("Address is : %p\n",f);
    printf("Data is : %s\n",f); 
    
    
    return 0;
}    