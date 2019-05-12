#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main()
{
	int sockfd, commfd, len, ch;
	char msg[100];
	struct sockaddr_in sa, cli;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket opened\n");

	bzero(&sa, sizeof(sa));
	sa.sin_family = AF_INET;
	sa.sin_port = htons(5600);
	connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
	printf("Connected succesfully...\n");

	bzero(msg, 100);
	read(sockfd, msg, 100);
	printf("Messsage recieved: %s", msg);
	return 0;
}
