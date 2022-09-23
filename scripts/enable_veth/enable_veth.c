//
// Created by jgodinho on 22-09-2022.
//

#include "enable_veth.h"

static const char CHILD_ENABLE_VETH[] = "ip -n %s link set %s up";
static const char PARENT_ENABLE_VETH[] = "ip link set %s up";

void child_enable_veth(char *child_namespace_name, char *child_veth_name) {
    printf("enable veth\n");
    char command[256];
    if (sprintf(command, CHILD_ENABLE_VETH, child_namespace_name, child_veth_name) < 0) {
        printf("Error formatting child_enable_veth command\n");
        exit(0);
    }
    if (system(command) == -1) {
        printf("Error while running child_enable_veth command\n");
        exit(0);
    }
}

void parent_enable_veth(char *parent_veth_name) {
    char command[256];
    if (sprintf(command, PARENT_ENABLE_VETH, parent_veth_name) < 0) {
        printf("Error formatting parent_enable_veth command\n");
        exit(0);
    }
    if (system(command) == -1) {
        printf("Error while running parent_enable_veth command\n");
        exit(0);
    }
}
