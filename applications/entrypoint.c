//
// Created by jgodinho on 22-09-2022.
//

#include "entrypoint.h"

static const char IP_FORMAT[] = "10.10.0.%d/16";
static const char CONTAINER_NAMESPACE_FORMAT[] = "containerns%d";
static const char ENTRYPOINT_VETH_FORMAT[] = "entrypointveth%d";
static const char CONTAINER_VETH_FORMAT[] = "containerveth%d";
static int ip_count = 1;
static int container_namespace_count = 0;
static int entrypoint_veth_count = 0;
static int container_veth_count = 0;

void create_new_application() {
    char entrypoint_ip[256], container_ip[256], container_namespace_name[256], entrypoint_veth_name[256], container_veth_name[256];
    if (sprintf(entrypoint_ip, IP_FORMAT, ip_count++) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    if (sprintf(container_ip, IP_FORMAT, ip_count++) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    if (sprintf(container_namespace_name, CONTAINER_NAMESPACE_FORMAT, container_namespace_count++) < 0) {
        printf("Error formatting container namespace\n");
        exit(0);
    }
    if (sprintf(entrypoint_veth_name, ENTRYPOINT_VETH_FORMAT, entrypoint_veth_count++) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    if (sprintf(container_veth_name, CONTAINER_VETH_FORMAT, container_veth_count++) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    isolate_container(entrypoint_ip, container_ip, container_namespace_name, entrypoint_veth_name, container_veth_name);
}

void run_primary_application() {
    create_new_application();
    create_new_application();
}
