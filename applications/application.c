//
// Created by jgodinho on 22-09-2022.
//

#include "application.h"

#define PORT 8081

void start_isolation(char *child_namespace_name, char *parent_veth_name, char *child_veth_name, char *ip) {
    create_namespace(child_namespace_name);
    enable_lo(child_namespace_name);
    create_veth(parent_veth_name, child_veth_name);
    link_veth(child_veth_name, child_namespace_name);
    assign_ip(child_namespace_name, ip, parent_veth_name);
    parent_enable_veth(parent_veth_name);
    child_enable_veth(child_namespace_name, child_veth_name);
}

void isolate(char *child_namespace_name) {
    unshare_thread();
    set_namespace(child_namespace_name);
}

void run_application_in_thread(char *child_namespace_name) {
    int server_sock;
    printf("hello\n");
    isolate(child_namespace_name);

    server_sock = create_server(PORT);
    //while (1) {
        char buffer[256];
        int client_sock = accept_connection(server_sock);
        printf("Hllo\n");
        receive_message(client_sock, buffer);
        printf("message: %s\n", buffer);
        respond(client_sock);
        close(client_sock);
    //}

    close(server_sock);
}

void run_application(char *ip, char *child_namespace_name, char *parent_veth_name, char *child_veth_name) {
    start_isolation(child_namespace_name, parent_veth_name, child_veth_name, ip);

    // child
    if (fork() == 0) {
        run_application_in_thread(child_namespace_name);
        exit(0);
    } else { // parent
    }
}
