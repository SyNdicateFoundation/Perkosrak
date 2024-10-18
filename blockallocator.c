#include "blockallocator.h"

#include <stdlib.h>
#include "cutils.h"
#include "logger.h"

Block* createBlock(const size_t size) {
    Block* block = malloc(sizeof(Block));
    block->block = malloc(size);
    try {
        if (!block || !block->block)
            throw();
        block->maxSize = size;
        block->usedSize = 0;
        block->next = NULL;
    } catch{
        if (block) {
            if (block->block)
                free(block->block);
            free(block);
        }
        error("BA", "Failed to make a block");
        return NULL;
    }
    return block;
}
Allocator* createAllocator(const size_t size) {
    Allocator* allocator = malloc(sizeof(Allocator));
    allocator->current = createBlock(size);
    try {
        if(!allocator || !allocator->current)
            throw();
        allocator->size = size;
    }catch{
        if (allocator) {
            if (allocator->current)
                free(allocator->current);
            free(allocator);
        }
        error("BA", "Failed to create an allocator");
        return NULL;
    }
    return allocator;
}
void* allocateBlock(Allocator* allocator, size_t size) {
    Block* block = allocator->current;
    if (block->usedSize + size > block->maxSize) {
        try {
            Block* newblock = createBlock(allocator->size > size ? allocator->size : size);
            if (!newblock) throw();

            newblock->next = allocator->current;
            allocator->current = newblock;
            block = newblock;
        }catch{
            return NULL;
        }
    }
    void* memory = (char*)block->block + block->usedSize;
    block->usedSize = block->usedSize + size;
    return memory;
}
void freeBlock(Allocator* allocator) {
    for(Block* block = allocator->current; block; free(allocator)) {
        Block* next = block->next;
        free(block->block);
        free(block);
        block = next;
    }
}