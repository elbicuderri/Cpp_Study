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

// this program
// find the file in the server
// and print the contents of the file to the client

int main(int argc, char** argv)
{
	int sfd, cfd, port, clientlen;
	// 

	FILE* fp;

	char inmsg[MAXLINE], outmsg[MAXLINE];

	struct sockaddr_in serveraddr, clientaddr;

	// struct in_addr serveraddr, clientaddr;

	struct hostent* hp;

	char* haddrp;

	signal(SIGCHLD, SIG_IGN);

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);
		exit(0);
	}

	port = atoi(argv[1]);

	sfd = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL); // make socket
	// internet socket use AF_INET (*unix_socket use AF_UNIX)

	bzero((char*)&serveraddr, sizeof(serveraddr));

	// /* Set N bytes of S to 0.  */
	// extern void bzero (void *__s, size_t __n) __THROW __nonnull ((1));

	serveraddr.sin_family = AF_INET;

	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	// htonl : long int ( host byte order -> network byte order )
	serveraddr.sin_port = htons((unsigned short)port);
	// htons : short int ( host byte order -> network byte order )

	bind(sfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));

	listen(sfd, 5);

	while (1)
	{
		clientlen = sizeof(clientaddr);

		cfd = accept(sfd, (struct sockaddr*)&clientaddr, &clientlen);
		// make socket connection
		// return copy of socket decriptor
		// get information of client socket by clientaddr parameters
		// this make a decision of ip and port number of client

		haddrp = inet_ntoa(clientaddr.sin_addr);
		// return A.B.C.D format string correspoing to IP address
		// unsigned long inet_addr(char* string); -> return binary data
		// a = (ip address of client stored in struct in_addr)
		// format a to string format 

		printf("server:%s(%d)is connected to\n", haddrp, clientaddr.sin_port);

		if (fork() == 0)
		{
			readLine(cfd, inmsg);
			fp = fopen(inmsg, "r");
			if (fp == NULL)
			{
				write(cfd, "No file", 10);
			}
			else
			{
				while (fgets(outmsg, MAXLINE, fp) != NULL)
					write(cfd, outmsg, strlen(outmsg) + 1);
			}
			close(cfd);
			exit(0);
		}
		else { close(cfd); }
	}

}

readLine(int fd, char* str)
{
	int n;
	do {
		n = read(fd, str, 1);
	} while (n > 0 && *str++ != NULL);

	return(n > 0);
}


// $ fserver 5000 &
// server:%s(%d)is connected to
// $ fclient cs.sookmyung.ac.kr 5000