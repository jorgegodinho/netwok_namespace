//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_CLIENT_H
#define NETWORK_NAMESPACES_CLIENT_H

#include "../socket/socket.h"

int connect_to_server(int port, char *host);
void send_message(int server_sock, char *message);

#endif //NETWORK_NAMESPACES_CLIENT_H
