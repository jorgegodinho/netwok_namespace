//
// Created by jgodinho on 22-09-2022.
//

#include "link_veth.h"

static const char LINK_VETH[] = "ip link set %s netns %s";

void link_veth(char *container_veth_name, char *container_namespace_name) {
    char command[256];
    if (sprintf(command, LINK_VETH, container_veth_name, container_namespace_name) < 0) {
        printf("Error formatting link_veth command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running link_veth command\n");
        exit(0);
    }
}
