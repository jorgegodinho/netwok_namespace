//
// Created by jgodinho on 22-09-2022.
//

#include "socket.h"

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error while creating socket\n");
        exit(0);
    }
    return sockfd;
}

void bind_socket_host(int sockfd, int port, char * host) {
    struct sockaddr_in servaddr, cli;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host);
    servaddr.sin_port = htons(port);

    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Error while binding socket\n");
        exit(0);
    }

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed\n");
        exit(0);
    }
}

void bind_socket(int sockfd, int port) {
    struct sockaddr_in servaddr, cli;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Error while binding socket\n");
        exit(0);
    }

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed\n");
        exit(0);
    }
}
