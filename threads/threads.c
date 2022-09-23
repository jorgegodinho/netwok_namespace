//
// Created by jgodinho on 21-09-2022.
//

#include "threads.h"

void create_thread(pthread_t *thread, void *function, void *args) {
    pthread_create(thread, NULL, function, args);
    printf("Created thread with id: %lu\n", *thread);
}
void join_thread(pthread_t thread) {
    pthread_join(thread, NULL);
    printf("Joined thread with id: %lu\n", thread);
}
