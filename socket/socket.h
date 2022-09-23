//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_SOCKET_H
#define NETWORK_NAMESPACES_SOCKET_H

#define SA struct sockaddr

#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

int create_socket();
void bind_socket_host(int sockfd, int port, char * host);
void bind_socket(int sockfd, int port);

#endif //NETWORK_NAMESPACES_SOCKET_H
