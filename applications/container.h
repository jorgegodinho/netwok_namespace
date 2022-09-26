//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_CONTAINER_H
#define NETWORK_NAMESPACES_CONTAINER_H

#include "../scripts/add_address/add_address.h"
#include "../scripts/create_namespace/create_namespace.h"
#include "../scripts/create_veth/create_veth.h"
#include "../scripts/enable_lo/enable_lo.h"
#include "../scripts/enable_veth/enable_veth.h"
#include "../scripts/link_veth/link_veth.h"
#include "../scripts/set_namespace/set_namespace.h"
#include "../scripts/set_default_gateway/set_default_gateway.h"
#include "../server/server.h"
#include <string.h>

void isolate_container(char *entrypoint_ip, char *container_ip, char *container_namespace_name, char *entrypoint_veth_name, char *container_veth_name);

#endif //NETWORK_NAMESPACES_CONTAINER_H
