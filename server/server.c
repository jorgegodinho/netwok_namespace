//
// Created by jgodinho on 26-09-2022.
//

#include "server.h"

static const char JAVA_COMMAND[] = "/usr/bin/java -jar ../http-server.jar";

void run_java_server() {
    if (system(JAVA_COMMAND) == -1) {
        printf("Error while running java server\n");
        exit(0);
    }
}
