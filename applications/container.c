//
// Created by jgodinho on 22-09-2022.
//

#include "container.h"

void start_isolation(char *container_namespace_name, char *entrypoint_veth_name, char *container_veth_name, char *entrypoint_ip, char *container_ip) {
    create_namespace(container_namespace_name);
    enable_lo(container_namespace_name);
    create_veth(entrypoint_veth_name, container_veth_name);
    link_veth(container_veth_name, container_namespace_name);
    add_address_to_entrypoint_namespace(entrypoint_ip, entrypoint_veth_name);
    add_address_to_container_namespace(container_namespace_name, container_ip, container_veth_name);
    entrypoint_enable_veth(entrypoint_veth_name);
    container_enable_veth(container_namespace_name, container_veth_name);
    set_container_default_network_gateway(container_namespace_name, strtok(entrypoint_ip, "/"), container_veth_name);
}

void isolate(char *container_namespace_name) {
    unshare_thread();
    set_namespace(container_namespace_name);
}

void isolate_container(char *entrypoint_ip, char *container_ip, char *container_namespace_name, char *entrypoint_veth_name, char *container_veth_name) {
    start_isolation(container_namespace_name, entrypoint_veth_name, container_veth_name, entrypoint_ip, container_ip);

    // container process
    if (fork() == 0) {
        isolate(container_namespace_name);
        exit(0);
    }
}
