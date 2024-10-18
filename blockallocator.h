#ifndef BLOCKALLOCATOR_H
#define BLOCKALLOCATOR_H
#include <stddef.h>

typedef struct Block {
    size_t maxSize;
    size_t usedSize;
    void* block;
    struct Block* next;
} Block;

typedef struct Allocator {
    Block* current;
    size_t size;
} Allocator;

Block* createBlock(size_t size);
Allocator* createAllocator(size_t size);
void* allocateBlock(Allocator* allocator, size_t size);
void freeBlock(Allocator* allocator);

#endif //BLOCKALLOCATOR_H
