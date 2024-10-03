#ifndef THREADS_H
#define THREADS_H

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

struct thread {
    int id;
    bool isTerminated;
    bool isDone;
};


extern struct thread threadss[];
extern pthread_t threads[];

void createThread(int id, void* (*run)(void*), void* args);
void mergeThread(int id);
void detachThread(int id);

#endif
