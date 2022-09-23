//
// Created by jgodinho on 22-09-2022.
//

#include "create_namespace.h"

static const char CREATE_NAMESPACE[] = "ip netns add %s";

void create_namespace(char *child_namespace_name) {
    char command[256];
    if (sprintf(command, CREATE_NAMESPACE, child_namespace_name) < 0) {
        printf("Error formatting create_namespace command\n");
        exit(0);
    }
    if (system(command) == -1) {
        printf("Error while running create_namespace command\n");
        exit(0);
    }
}
