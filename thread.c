#include "thread.h"

struct thread threadss[];
pthread_t threads[];

void createThread(int id, void* (*run)(void*), void* args) {
    threadss[id] = (struct thread){id, false, false};
    pthread_create(&threads[id], NULL, run, args);
}

void mergeThread(int id) {
    pthread_join(threads[id], NULL);
}

void detachThread(int id){
    pthread_cancel(threads[id]);
}