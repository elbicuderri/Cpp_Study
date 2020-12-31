#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define DEFAULT_PROTOCOL 0

int main(int argc, char** argv)
{
    int client_fd, port, result; // file descriptor

    char* host;

    int height, width;

    struct sockaddr_in server_addr;

    struct hostent* hp;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		exit(0);
	}

	host = argv[1]; // get name of host (ip address)
	port = atoi(argv[2]); // get port number of host 

    client_fd = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL);

    // fill the ip address and port number of server
	if ((hp = gethostbyname(host)) == NULL) // return type : struct hostent*
    { 
		perror("gethostbyname error"); // host find error
	}

    bzero((char*)&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;

    bcopy((char*)hp->h_addr_list[0],
    (char*)&server_addr.sin_addr.s_addr, hp->h_length);

    server_addr.sin_port = htons(port);

    // server_addr.sin_family = AF_INET;
    // server_addr.sin_addr.s_addr = *(u_long *)hp->h_addr_list[0];
    // server_addr.sin_port = htons(port);

    do {
        result = connect(client_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (result == -1) { sleep(1); }
    } while (result == -1);

    printf("What is your image's height?\n");
    scanf("%d", &height);
    write(client_fd, (const void*)&height, sizeof(height));
    // write(server_fd, c_height, height);??
    printf("What is your image's width?\n");
    scanf("%d", &width);
    write(client_fd, (const void*)&width, sizeof(width));
    // write(server_fd, c_width, width);??

    close(client_fd);
    exit(0);
}