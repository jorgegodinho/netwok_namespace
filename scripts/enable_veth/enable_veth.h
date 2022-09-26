//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_ENABLE_VETH_H
#define NETWORK_NAMESPACES_ENABLE_VETH_H

#include <stdio.h>
#include <stdlib.h>

void container_enable_veth(char *container_namespace_name, char *container_veth_name);
void entrypoint_enable_veth(char *entrypoint_veth_name);

#endif //NETWORK_NAMESPACES_ENABLE_VETH_H
