//
// Created by jgodinho on 22-09-2022.
//

#define _GNU_SOURCE

#include "unshare.h"

void unshare_thread() {
    if (unshare(CLONE_NEWNET) == -1) {
        printf("Error while running unshare command\n");
        exit(0);
    }
    printf("ola\n");
}
