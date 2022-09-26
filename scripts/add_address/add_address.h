//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_ADD_ADDRESS_H
#define NETWORK_NAMESPACES_ADD_ADDRESS_H

#include <stdio.h>
#include <stdlib.h>

void add_address_to_entrypoint_namespace(
    char* entrypoint_ip,
    char *entrypoint_veth_name);

void add_address_to_container_namespace(
    char *container_namespace_name,
    char* container_ip,
    char *container_veth_name);

#endif //NETWORK_NAMESPACES_ADD_ADDRESS_H
