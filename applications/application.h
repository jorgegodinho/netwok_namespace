//
// Created by jgodinho on 22-09-2022.
//

#ifndef NETWORK_NAMESPACES_APPLICATION_H
#define NETWORK_NAMESPACES_APPLICATION_H

#include "../threads/threads.h"
#include "../server/server.h"
#include "../scripts/assign_ip/assign_ip.h"
#include "../scripts/create_namespace/create_namespace.h"
#include "../scripts/create_veth/create_veth.h"
#include "../scripts/enable_lo/enable_lo.h"
#include "../scripts/enable_veth/enable_veth.h"
#include "../scripts/link_veth/link_veth.h"
#include "../scripts/unshare/unshare.h"
#include "../scripts/set_namespace/set_namespace.h"

typedef struct {
    char *child_namespace_name;
}application_args;

void run_application(char *ip, char *child_namespace_name, char *parent_veth_name, char *child_veth_name);

#endif //NETWORK_NAMESPACES_APPLICATION_H
