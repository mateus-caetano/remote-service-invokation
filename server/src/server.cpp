#include "../headers/server.h"

void Server::getRequest()
{
    char buffer[MAXLINE];
    socklen_t len;
    std::string remoteMethod, response;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr,
             sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    std::cout << "server is running..." << std::endl
              << std::endl;

    while (true)
    {
        len = sizeof(cliaddr);

        recvfrom(sockfd, (char *)buffer, MAXLINE,
                 MSG_WAITALL, (struct sockaddr *)&cliaddr,
                 &len);

        remoteMethod = buffer;
        remoteMethod = remoteMethod[remoteMethod.find(",") + 1];

        response = dispatch.invoke(buffer, remoteMethod);

        sendResponse(response);
    }
}

void Server::sendResponse(std::string response)
{
    socklen_t len = sizeof(cliaddr);

    sendto(sockfd, (const char *)response.c_str(), response.size(),
           MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
           len);
    printf("Confirm message sent.\n");
}