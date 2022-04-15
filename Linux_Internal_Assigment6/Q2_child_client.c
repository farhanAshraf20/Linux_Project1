#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<arpa/inet.h>

int main()
{
	char *serv_ip = "127.0.0.1";
	int f_sock_fd, f_retuen_val;

	struct sockaddr_in servaddr;

	f_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(f_sock_fd < 0)
	{
		perror("sock: ");
		exit(1);
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8000);
	inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);

	f_retuen_val = connect(f_sock_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
	if(f_retuen_val < 0)
	{
		perror("connect: ");
		exit(2);
	}

	printf("client established connection with server\n");

	while(1)
	{
		int n;

		char s_buffer[200];
		char r_buffer[200];

		printf("\nEnter the data to send to the server: \n");
		gets(s_buffer);
	
		write(f_sock_fd , s_buffer, strlen(s_buffer));

		n = read(f_sock_fd, r_buffer, sizeof(r_buffer));
		r_buffer[n] = '\0';
		printf("\nData rec'd from server:\n %s\n", r_buffer);

//		printf("In while\n");
	}

	close(f_sock_fd);

	return 0;
}