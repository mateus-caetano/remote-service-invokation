#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iostream>

#include "../../client.pb.h"

#define PORT 8080
#define MAXLINE 1024

class Server
{
public:
    void getRequest();
    void sendResponse();

private:
    struct sockaddr_in servaddr, cliaddr;
    int sockfd;
};