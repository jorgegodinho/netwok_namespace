//
// Created by jgodinho on 26-09-2022.
//

#ifndef NETWORK_NAMESPACES_SET_DEFAULT_GATEWAY_H
#define NETWORK_NAMESPACES_SET_DEFAULT_GATEWAY_H

#include <stdio.h>
#include <stdlib.h>

void set_container_default_network_gateway(
    char *container_namespace_name,
    char *entrypoint_ip,
    char *container_veth_name);

#endif //NETWORK_NAMESPACES_SET_DEFAULT_GATEWAY_H
