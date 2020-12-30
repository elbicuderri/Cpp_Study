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

void toUpper(char* in, char* out);

int readLine(int fd, char* str);

// lower -> capital
int main()
{
    int sfd, cfd, clientlen;

    char inmsg[MAXLINE], outmsg[MAXLINE];

    struct sockaddr_un serverAddr, clinetAddr;

    signal(SIGCHLD, SIG_IGN); // create unix socket
    
    clientlen = sizeof(clinetAddr);

    sfd = socket(AF_UNIX, SOCK_STREAM, DEFAULT_PROTOCOL); // socket fd
    // fd : file descriptor
    // domain : AF_UNIX
    // type : SOCK_STREAM
    // protocol : DEFAULT_PROTOCOL

    //===================================================================
    serverAddr.sun_family = AF_UNIX; // AF_UNIX : 1 (unsigned short)

    strcpy(serverAddr.sun_path, "convert"); // socket name : "convert"

    // unlink("convert"); // if alreay named, delete older name
    // unix("convert"); // if alreay named, delete older name

    bind(sfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)); 
    // system calling -> socket name "convert" setting
    //===================================================================

    listen(sfd, 5);
    // stand by -> set max len of queue(request) == 5

    while (1) // accept offering of client
    {
        cfd = accept(sfd, (struct sockaddr*)&clinetAddr, &clientlen);
        // client file descriptor
        // success : 0, fail : -1

        if (fork() == 0) 
        {
            readLine(cfd, inmsg);
            // readline from client... maybe?
            toUpper(inmsg, outmsg);
            // lower -> capital
            fwrite(cfd, outmsg, strlen(outmsg)+1);
            // write letters in client
            pclose(cfd);
            // close client socket
            exit(0);
        }
        else { close(cfd); }
    }

}

void toUpper(char* in, char* out)
{
    int i;
    for (int i = 0; i < strlen(in); i++) 
    {
        if (islower(in[i])) 
        {
            out[i] = toupper(in[i]);
        }
        else 
        {
            out[i] = in[i];
        }
        out[i] = NULL; // last of char*
    }
}

int readLine(int fd, char* str)
{
    int n;
    do {
        n = read(fd, str, 1);
    } while (n > 0 && *str++ != NULL);

    return(n > 0);
}

// $ cserver &
// [1] 32014
// cclient
