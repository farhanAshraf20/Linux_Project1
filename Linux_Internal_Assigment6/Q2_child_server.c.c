#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdlib.h>

void handleClient(int f_connfd)
{
	int n;
	char f_buff[200];

	n = read(f_connfd, f_buff, 200);
	f_buff[n] = '\0';

	printf("Data record from client : %s\n",f_buff);
	printf("\nrequested handled by server: %d\n",getpid());
	write(f_connfd, "Good bye", 8);

	printf("\nData sended to client\n");
        exit(0);	//terminate child
}

int main()
{
	int f_sock_fd, f_connfd, f_retval;
	pid_t childpid;

	socklen_t clilen;
	struct sockaddr_in clientaddr, servaddr;

	f_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(f_sock_fd < 0)
	{
		perror("sock: ");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //htonl(INADDR_ANY);
	servaddr.sin_port = htons(8000); // 16 bit short 	TCP protocol HTTP---port

	f_retval = bind(f_sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(f_retval < 0)
	{
		perror("bind: ");
		exit(2);
	}

	listen(f_sock_fd, 5);

	while(1)
	{
		char s_buf[200];
		char r_buf[200];
		pid_t p;

		int n;

		clilen = sizeof(clientaddr);
		f_connfd = accept(f_sock_fd, (struct sockaddr *) &clientaddr, &clilen);
		printf("client connected\n");
		
		p = fork();
		if(p == 0)
		{
			close(f_sock_fd);
			handleClient(f_connfd);
		}
		close(f_connfd);
	}

//	close(f_sock_fd);

	return 0;
}
