#include "../headers/server.h"

void Server::getRequest()
{
    char buffer[MAXLINE];
    proto::Client client;

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

    int n;
    socklen_t len;
    while (true)
    {
        len = sizeof(cliaddr);

        n = recvfrom(sockfd, (char *)buffer, MAXLINE,
                     MSG_WAITALL, (struct sockaddr *)&cliaddr,
                     &len);

        client.ParseFromString(buffer);

        std::cout << "Client : {id: " << client.id() << ", nome: " << client.nome() << "}" << std::endl;

        sendResponse();
    }
}

void Server::sendResponse()
{
    std::string response = "ok";
    socklen_t len = sizeof(cliaddr);

    sendto(sockfd, (const char *)response.c_str(), response.size(),
           MSG_CONFIRM, (const struct sockaddr *)&cliaddr,
           len);
    printf("Confirm message sent.\n");
}