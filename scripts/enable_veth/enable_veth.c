//
// Created by jgodinho on 22-09-2022.
//

#include "enable_veth.h"

static const char CONTAINER_ENABLE_VETH[] = "ip -n %s link set %s up";
static const char ENTRYPOINT_ENABLE_VETH[] = "ip link set %s up";

void container_enable_veth(char *container_namespace_name, char *container_veth_name) {
    char command[256];
    if (sprintf(command, CONTAINER_ENABLE_VETH, container_namespace_name, container_veth_name) < 0) {
        printf("Error formatting container_enable_veth command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running container_enable_veth command\n");
        exit(0);
    }
}

void entrypoint_enable_veth(char *entrypoint_veth_name) {
    char command[256];
    if (sprintf(command, ENTRYPOINT_ENABLE_VETH, entrypoint_veth_name) < 0) {
        printf("Error formatting entrypoint_enable_veth command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running entrypoint_enable_veth command\n");
        exit(0);
    }
}
