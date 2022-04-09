/*****************************************************************************************************
Q.2 Write a program that uses msgctl() and prints number of messages,number of bytes in message
queue and also get Maximum number of bytes in queue for already existing message queue
and also remove message queue at the end.
Date : 08-Apr-2022
Farhan Ashraf
*Message Queue (Tx)
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

	id = msgget(key, IPC_CREAT|0644);              // Creating a message queue id
	
        if(id < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Message queue id: %d\n",id);

	
	q1.mytype = 5;
	strcpy(q1.data, "msg queue transmitter");

	q2.mytype = 7;
	strcpy(q2.data, "transmitting: farhan");

	msgsnd(id, &q1, strlen(q1.data)+1, 0);
	perror("msgsnd1");

	msgsnd(id, &q2, strlen(q2.data)+1, 0);
	perror("msgsnd2");

	
	msgctl(id, IPC_STAT, NULL);

	// printing contents of message queue through struct msgid_ds
	
    printf("Contents from the struct are: \n");
	printf("no of msges in queue: %d\n",mybuff.msg_qnum);
	printf("no of bytes in queue: %d\n",mybuff.msg_cbytes);
	printf("max no of bytes in queue: %d\n",mybuff.msg_qbytes);

	return 0;
}
