//
// Created by jgodinho on 22-09-2022.
//

#include "create_namespace.h"

static const char CREATE_NAMESPACE[] = "ip netns add %s";

void create_namespace(char *container_namespace_name) {
    char command[256];
    if (sprintf(command, CREATE_NAMESPACE, container_namespace_name) < 0) {
        printf("Error formatting create_namespace command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running create_namespace command\n");
        exit(0);
    }
}
