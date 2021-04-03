#include "../headers/client.h"

std::string Client::sendRequest(std::string msg)
{
    int sockfd;
    std::string buffer;
    // char buffer[MAXLINE];
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    int n;
    socklen_t len;

    sendto(sockfd, (const char *)msg.c_str(), (size_t)msg.size(),
           MSG_CONFIRM, (const struct sockaddr *)&servaddr,
           (socklen_t)sizeof(servaddr));

    printf("Hello message sent.\n");

    n = recvfrom(sockfd, (char *)buffer.c_str(), MAXLINE,
                 MSG_WAITALL, (struct sockaddr *)&servaddr,
                 &len);

    std::cout << "buffer: " << buffer << std::endl;

    close(sockfd);

    return buffer;
}