//
// Created by jgodinho on 23-09-2022.
//

#include "open_port.h"

static const char OPEN_PORT[] = "ip netns exec %s ufw allow %d";

void open_port(char *container_namespace_name, int port) {
    char command[256];
    if (sprintf(command, OPEN_PORT, container_namespace_name, port) < 0) {
        printf("Error formatting open_port command\n");
        exit(0);
    }
    if (system(command) == -1) {
        printf("Error while running open_port command\n");
        exit(0);
    }
}
