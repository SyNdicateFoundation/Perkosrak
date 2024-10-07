#include "garbagecollector.h"

extern Object* heap = NULL;
extern size_t heapSize = maxHeapSize;
extern size_t usedHeap = 0;

void* allocate(size_t size){
    try{
        if (usedHeap + size > maxHeapSize)
            throw();

        Object* newObject = malloc(sizeof(Object) + size);
        newObject->collect = false;
        newObject->size = size;
        newObject->object = heap;

        heap = newObject;

        usedHeap = usedHeap + (sizeof(Object) + size);
        return newObject;
    } catch{
        error("GC", "An error resulted when allocating an object to memory by garbage collector\n");
        return NULL;
    }
}
void collect(Object* object){
    try{
        if(object == NULL || object->collect) throw();
        object->collect = true;
    }
}
int gc_call() {
    Object* next = heap;
    Object* last = NULL;

    while (next != NULL) {
        if (!next->collect) {
            last = next;
            return 0;
        }

        if (last == NULL)
            heap = next->object;
        else
            last->object = next->object;

        usedHeap -= sizeof(Object) + next->size;
        Object* temp = next;
        next = next->object;
        free(temp);
    }

    next = next->object;

    return 0;
}