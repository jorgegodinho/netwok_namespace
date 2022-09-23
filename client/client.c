//
// Created by jgodinho on 22-09-2022.
//

#include "client.h"

int connect_to_server(int port, char *host) {
    int sockfd;
    struct sockaddr_in server_addr;
    sockfd = create_socket();
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    // Send connection request to server:
    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("Unable to connect\n");
        exit(0);
    }
    return sockfd;
}

void send_message(int server_sock, char *message) {
    char buffer[256] = "test";

    if (write(server_sock, buffer, strlen(buffer)) < 0) {
        printf("Unable to send message\n");
        exit(0);
    }
    memset(buffer,'\0',sizeof(buffer));

    if (read(server_sock, buffer, 255)  < 0) {
        printf("Error while receiving server message\n");
        exit(0);
    }

    printf("Server message: %s\n", buffer);
}
