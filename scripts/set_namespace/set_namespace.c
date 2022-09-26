//
// Created by jgodinho on 22-09-2022.
//

#define _GNU_SOURCE

#include "set_namespace.h"

void set_namespace(char *container_namespace_name) {
    int namespace;
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "/var/run/netns/%s", container_namespace_name);
    namespace = open(path, O_RDONLY);
    if (namespace == -1) {
        printf("Error while opening network namespace file\n");
        exit(0);
    }
    printf("Setting network namespace '%s' to this process\n", container_namespace_name);
    if (setns(namespace, CLONE_NEWNET) == -1) {
        printf("Error while setting new namespace\n");
        exit(0);
    }
}

