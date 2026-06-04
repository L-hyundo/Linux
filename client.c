#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int main()
{
	int sockfd;
	struct sockaddr_in server_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9000);

	inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
	connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	char msg[] = "hello Server";

	send(sockfd, msg, strlen(msg)+1, 0);

	close(sockfd);

	return 0;	
}
