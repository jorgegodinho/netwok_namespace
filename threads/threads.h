//
// Created by jgodinho on 21-09-2022.
//

#ifndef NETWORK_NAMESPACES_THREADS_H
#define NETWORK_NAMESPACES_THREADS_H

#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <sched.h>
#include "../server/server.h"

void create_thread(pthread_t *thread, void *function, void *args);
void join_thread(pthread_t thread);

#endif //NETWORK_NAMESPACES_THREADS_H
