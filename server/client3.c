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
#define MAXLINE 100


int main(int argc, char** argv)
{
	int sfd, port, result;

	char* host, inmsg[MAXLINE], outmsg[MAXLINE];

	struct sockaddr_in serverAddr;

	struct hostent* hp;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
		exit(0);
	}

	host = argv[1]; // get name of host
	port = atoi(argv[2]); // get port number of host

	sfd = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL);
	// make socket

	// fill the ip address and port number of server
	if ((hp = gethostbyname(host)) == NULL) { // return type : struct hostent*
		perror("gethostbyname error");
	} // host find error

	//===============================================================================
	bzero((char*)&serverAddr, sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;

	bcopy((char*)hp->h_addr_list[0],
		(char*)&serverAddr.sin_addr.s_addr, hp->h_length); // set the ip address of the server socket

	serverAddr.sin_port = htons(port); // set the port number of the server socket
	//===============================================================================
	// waiting
	do {
		result = connect(sfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
		if (result == -1) { sleep(1); } // wait for one second~
	} while (result == -1);

	// after connecting
	printf("Enter the name of the file to download:");
	scanf("%s", inmsg); // get the name of the file
	write(sfd, inmsg, strlen(inmsg) + 1);

	while (readLine(sfd, outmsg)) {
		printf("%s\n", outmsg); // print contents of the file to the client by socket connection
	}

	close(sfd);
	exit(0);

}

readLine(int fd, char* str)
{
	int n;
	do {
		n = read(fd, str, 1);
	} while (n > 0 && *str++ != NULL);

	return(n > 0);
}