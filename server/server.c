//
// Created by jgodinho on 22-09-2022.
//

#include "server.h"

int accept_connection(int sockfd) {
    struct sockaddr_in client_addr;
    int client_sock;
    socklen_t client_size;
    client_size = sizeof(client_addr);
    client_sock = accept(sockfd, (struct sockaddr*)&client_addr, &client_size);
    if (client_sock < 0) {
        printf("Could not accept connection\n");
        exit(0);
    } else {
        printf("Client connected at IP %s and port %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }
    return client_sock;
}

void respond(int client_sock) {
    char server_message[2000];
    memset(server_message, '\0', sizeof(server_message));
    strcpy(server_message, "This is the server's message\n");

    if (write(client_sock, server_message, strlen(server_message)) < 0) {
        printf("Could not send message to client\n");
        exit(0);
    }
}

int create_server(int port) {
    int sockfd = create_socket();
    bind_socket(sockfd, port);
    return sockfd;
}

int create_server_host(int port, char *host) {
    int sockfd = create_socket();
    bind_socket_host(sockfd, port, host);
    return sockfd;
}

void receive_message(int client_sock, char *buffer) {
    if (read(client_sock, buffer, 255) < 0) {
        printf("Could not receive message from client\n");
        exit(0);
    }
}
