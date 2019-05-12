#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

int main()
{
	char str[100];
	int sockfd, commfd;
	struct sockaddr_in sa, cli;
	time_t tick;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("Socket created...\n");

	bzero(&sa, sizeof(sa));
	sa.sin_port = htons(5600);
	sa.sin_addr.s_addr = htonl(0);

	bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
	listen(sockfd, 10);

	printf("Socket started listening....\n");

	while(1)
	{
		bzero(str, 100);

		int len = sizeof(int);
		commfd = accept(sockfd, (struct sockaddr *)&cli, &len);
		tick = time(NULL);
		snprintf(str, sizeof(str), "%s", ctime(&tick));
		write(commfd, str, 100);
	}
	return 0;
}
