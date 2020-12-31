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
    int server_fd, client_fd, port, client_len; // file descriptor

    int height, width;

    struct sockaddr_in server_addr, client_addr; // address

    struct hostent* hp;

    char* haddrp;

    signal(SIGCHLD, SIG_IGN);

    if ( argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(0);
    }

    port = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, DEFAULT_PROTOCOL);

    bzero((char*)&server_addr, sizeof(server_addr));

    // memset((void *)&server_addr, 0x00, sizeof(serveraddr)); // 0x00 == '\0\'
    // similar things?

    server_addr.sin_family = AF_INET;

    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    server_addr.sin_port = htons((unsigned short)port);

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    listen(server_fd, 5);

    while (1) {

        client_len = sizeof(client_addr);

        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);

        hp = gethostbyaddr((char*)&client_addr.sin_addr.s_addr,
         sizeof(client_addr.sin_addr.s_addr), AF_INET);

        haddrp = inet_ntoa(client_addr.sin_addr);

        printf("server : %s (%s) %d connected\n", hp->h_name, haddrp, client_addr.sin_port);

        if (fork() == 0)
        {
            read(client_fd, (void*)&height, sizeof(height));
            read(client_fd, (void*)&width, sizeof(width));

            printf("\n");
            printf("height: %d\n", height);
            printf("width: %d\n", width);

            close(client_fd);
            exit(0);
        }
        else { close(client_fd); exit(0); }
    }

}