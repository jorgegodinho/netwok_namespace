//
// Created by jgodinho on 26-09-2022.
//

#include "set_default_gateway.h"

static const char SET_NETWORK_GATEWAY[] = "ip netns exec %s route add default gw %s %s";

void set_container_default_network_gateway(char * container_namespace_name, char *entrypoint_ip, char *container_veth_name) {
    char command[256];
    if (sprintf(command, SET_NETWORK_GATEWAY, container_namespace_name, entrypoint_ip, container_veth_name) < 0) {
        printf("Error formatting set_network_gateway command\n");
        exit(0);
    }
    if (system(command) == -1) {
        printf("Error while running set_network_gateway command\n");
        exit(0);
    }
}
