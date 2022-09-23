//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_SET_NAMESPACE_H
#define NETWORK_NAMESPACES_SET_NAMESPACE_H

#include <stdio.h>
#include <linux/limits.h>
#include <unistd.h>
#include <syscall.h>
#include <fcntl.h>
#include <sched.h>
#include <stdlib.h>

void set_namespace(char *child_namespace_name);

#endif //NETWORK_NAMESPACES_SET_NAMESPACE_H
