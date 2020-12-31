#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PROTOCOL 0
#define MAXLINE 100

int readLine(int fd, char* str);

int main()
{
    int sfd, clientfd, result;
    // int sfd, result;
    char inmsg[MAXLINE], outmsg[MAXLINE];
    struct sockaddr_un serverAddr;

    clientfd = socket(AF_UNIX, SOCK_STREAM, DEFAULT_PROTOCOL);
    serverAddr.sun_family = AF_UNIX;
    strcpy(serverAddr.sun_path, "convert");

    do {
        result = connect(sfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        if (result == -1) 
        {
            sleep(1);
        }
    } while (result == -1);

    printf("Enter the letters:\n");
    fgets(inmsg, MAXLINE, stdin);
    write(sfd, inmsg, strlen(inmsg)+1);

    readLine(sfd, outmsg);
    printf("%s --> \n%s", inmsg, outmsg);
    close(sfd);
    exit(0);
}

int readLine(int fd, char* str)
{
    int n;
    do {
        n = read(fd, str, 1);
    } while (n > 0 && *str++ != NULL);

    return(n > 0);
}