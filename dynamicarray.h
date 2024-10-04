#ifndef PERKOSRAK_DYNAMICARRAY_H
#define PERKOSRAK_DYNAMICARRAY_H
#include<stdlib.h>
#include<stdio.h>
#include "cutils.h"
#include "logger.h"
typedef struct dynamicarray{
    void* data;
    size_t size;
    size_t maxelements;
} DynamicArray;

DynamicArray* make_array(size_t initial_capacity);
void free_array(DynamicArray* array);
void append_array(DynamicArray* array, void* element, size_t element_size);
char* array_toString(DynamicArray* array);
#endif //PERKOSRAK_DYNAMICARRAY_H
