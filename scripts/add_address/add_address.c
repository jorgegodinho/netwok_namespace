//
// Created by jgodinho on 22-09-2022.
//

#include "add_address.h"

static const char ENTRYPOINT_ADD_ADDRESS[] = "ip addr add %s dev %s";
static const char CONTAINER_ADD_ADDRESS[] = "ip netns exec %s ip addr add %s dev %s";

void add_address_to_entrypoint_namespace(
    char* entrypoint_ip,
    char *entrypoint_veth_name)
{
    char command[256];
    if (sprintf(command, ENTRYPOINT_ADD_ADDRESS, entrypoint_ip, entrypoint_veth_name) < 0) {
        printf("Error formatting add_address_to_entrypoint_namespace command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running add_address_to_entrypoint_namespace command\n");
        exit(0);
    }
}

void add_address_to_container_namespace(
    char *container_namespace_name,
    char* container_ip,
    char *container_veth_name)
{
    char command[256];
    if (sprintf(command, CONTAINER_ADD_ADDRESS, container_namespace_name, container_ip, container_veth_name) < 0) {
        printf("Error formatting add_address_to_container_namespace command\n");
        exit(0);
    }
    printf("cmd: %s\n", command);
    if (system(command) == -1) {
        printf("Error while running add_address_to_container_namespace command\n");
        exit(0);
    }
}
