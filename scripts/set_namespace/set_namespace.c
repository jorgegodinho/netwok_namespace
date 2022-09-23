//
// Created by jgodinho on 22-09-2022.
//

#define _GNU_SOURCE

#include "set_namespace.h"

void set_namespace(char *child_namespace_name) {
    printf("set namespace\n");
    int namespace;
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "/var/run/netns/%s", child_namespace_name);
    namespace = open(path, O_RDONLY);
    if (namespace == -1) {
        printf("Error while opening network namespace file\n");
        exit(0);
    }
    if (setns(namespace, CLONE_NEWNET) == -1) {
        printf("Error while setting new namespace\n");
        exit(0);
    }
}

