//
// Created by jgodinho on 22-09-2022.
//

#include "main_application.h"

#define MAIN_APPLICATION_PORT 8080
#define APPLICATIONS_PORT 8081

static const char IP_FORMAT[] = "10.0.%d.1/24";
static const char CHILD_NAMESPACE_FORMAT[] = "jgnetns%d";
static const char PARENT_VETH_FORMAT[] = "jgparentveth%d";
static const char CHILD_VETH_FORMAT[] = "jgchildveth%d";
static int ip_count = 0;
static int child_namespace_count = 0;
static int parent_veth_count = 0;
static int child_veth_count = 0;

void create_new_application() {
    char ip[256], child_namespace_name[256], parent_veth_name[256], child_veth_name[256];
    if (sprintf(ip, IP_FORMAT, ip_count++) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    if (sprintf(child_namespace_name, CHILD_NAMESPACE_FORMAT, child_namespace_count++) < 0) {
        printf("Error formatting child namespace\n");
        exit(0);
    }
    if (sprintf(parent_veth_name, PARENT_VETH_FORMAT, parent_veth_count++) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    if (sprintf(child_veth_name, CHILD_VETH_FORMAT, child_veth_count++) < 0) {
        printf("Error formatting ip\n");
        exit(0);
    }
    run_application(ip, child_namespace_name, parent_veth_name, child_veth_name);
}

void run_primary_application() {
    create_new_application();

    int server_sock = create_server(MAIN_APPLICATION_PORT);

    //while (1) {
    char buffer[256];
    int client_sock = accept_connection(server_sock);
    receive_message(client_sock, buffer);
    printf("message: %s\n", buffer);

    int application_sock = connect_to_server(APPLICATIONS_PORT, "10.0.0.1");
    send_message(application_sock, "tets");
    close(application_sock);

    respond(client_sock);
    close(client_sock);
    //}

    close(server_sock);
}
