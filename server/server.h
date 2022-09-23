//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_SERVER_H
#define NETWORK_NAMESPACES_SERVER_H

#include "../socket/socket.h"

int accept_connection(int sockfd);
void receive_message(int client_sock, char *buffer);
void respond(int client_sock);
int create_server(int port);
int create_server_host(int port, char *host);

#endif //NETWORK_NAMESPACES_SERVER_H
