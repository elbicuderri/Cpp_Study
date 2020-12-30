#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define SERVER_PORT 18000

#define MAXLINE 4096

// #define SA struct sockaddr

// #define errno (*__errno_location ())

void err_n_die(const char* fmt, ...);

char* bin2hex(const unsigned char* input, size_t len);

#endif