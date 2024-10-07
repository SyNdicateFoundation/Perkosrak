#ifndef PERKOSRAK_GARBAGECOLLECTOR_H
#define PERKOSRAK_GARBAGECOLLECTOR_H

#include<stdlib.h>
#include<stdbool.h>
#include "logger.h"
#include "cutils.h"
#define maxHeapSize 1024

typedef struct Object{
    bool collect;
    size_t size;
    struct Object* object;
} Object;

extern Object* heap;
extern size_t heapSize;
extern size_t usedHeap;

void* allocate(size_t size);
void mark(Object* object);
int gc_call();

#endif //PERKOSRAK_GARBAGECOLLECTOR_H
