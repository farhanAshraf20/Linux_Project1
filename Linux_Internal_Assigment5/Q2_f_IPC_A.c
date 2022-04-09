/*****************************************************************************************************
Q.2 Write a program that uses msgctl() and prints number of messages,number of bytes in message
queue and also get Maximum number of bytes in queue for already existing message queue
and also remove message queue at the end.
Date : 08-Apr-2022
Farhan Ashraf
*Message Queue ctl (Rx)
***********************************************************************************************************/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>

#define key 33

struct msgqu
{
	long mytype;
	char data[512];
};

int main()
{
	int id;
	struct msgqu q1, q2;
	struct msqid_ds mybuff;

	id = msgget(key, IPC_CREAT|0644);              // Creating a id using msgget function
	if(id < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Message queue id: %d\n",id);

	
	msgctl(id, IPC_STAT, NULL);                          //  msgctl function to print the number of messages

	

    // printing contents of message queue through struct msgid_ds
	
    printf("Contents from the struct are: \n");
	printf("no of msges in queue: %d\n",mybuff.msg_qnum);
	printf("no of bytes in queue: %d\n",mybuff.msg_cbytes);
	printf("max no of bytes in queue: %d\n",mybuff.msg_qbytes);

	
	msgrcv(id, &q1, sizeof(q1), 5, 0);                     // msgrcv function used to recieve the type1 of message

	printf("Type1 is: %ld\n",q1.mytype);
	printf("Message1 is: %s\n",q1.data);

	msgrcv(id, &q2, sizeof(q2), 7, 0);                    // msgrcv function used to recieve the type2 of message

	printf("Type2 is: %ld\n",q2.mytype);
	printf("Message2 is: %s\n",q2.data);
	
    msgctl(id, IPC_RMID, NULL);                           // msgctl function used to print the messages in type1 and type2 

	return 0;