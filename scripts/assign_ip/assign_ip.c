//
// Created by jgodinho on 22-09-2022.
//

#include "assign_ip.h"

static const char ASSIGN_IP[] = "ip addr add %s dev %s";

void assign_ip(char *child_namespace_name, char* ip, char *child_veth_name) {
    char command[256];
    if (sprintf(command, ASSIGN_IP, ip, child_veth_name) < 0) {
        printf("Error formatting assign_ip command\n");
        exit(0);
    }
    if (system(command) == -1) {
        printf("Error while running assign_ip command\n");
        exit(0);
    }
}
