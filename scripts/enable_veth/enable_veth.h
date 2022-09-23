//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_ENABLE_VETH_H
#define NETWORK_NAMESPACES_ENABLE_VETH_H

#include <stdio.h>
#include <stdlib.h>

void child_enable_veth(char *child_namespace_name, char *child_veth_name);
void parent_enable_veth(char *parent_veth_name);

#endif //NETWORK_NAMESPACES_ENABLE_VETH_H
