#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
	int server_fd, client_fd;
	char buffer[1024];

	struct sockaddr_in server_addr;

	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(9000);

	bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

	listen(server_fd, 5);

	printf("서버 실행 중...\n");

	client_fd = accept(server_fd, NULL, NULL);

	printf("클라이언트 접속 성공\n");

	recv(client_fd, buffer, sizeof(buffer), 0);

	printf("받은 메시지: %s\n", buffer);

	close(client_fd);
	close(server_fd);

	return 0;
}
