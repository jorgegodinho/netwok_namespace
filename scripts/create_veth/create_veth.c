//
// Created by jgodinho on 22-09-2022.
//

#include "create_veth.h"

static const char CREATE_VETH[] = "ip link add %s type veth peer name %s";

void create_veth(char *entrypoint_veth_name, char *container_veth_name) {
    char command[256];
    if (sprintf(command, CREATE_VETH, entrypoint_veth_name, container_veth_name) < 0) {
        printf("Error formatting create_veth command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running create_veth command\n");
        exit(0);
    }
}