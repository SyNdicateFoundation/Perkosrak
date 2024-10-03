#include "dynamicarray.h"

DynamicArray* make_array(size_t maxelements) {
    DynamicArray *new_array = (DynamicArray *) malloc(sizeof(DynamicArray));
    try
    {
        new_array->data = malloc(maxelements);
        new_array->size = 0;
        new_array->maxelements = maxelements;

        if(new_array == NULL || new_array->data == NULL) throw();
    } catch{
        error("RUN", "Caught an exception while allocating an array!");
    }
    return new_array;
}
void free_array(DynamicArray* array){
    free(array->data);
    free(array);
}
void append(DynamicArray* array, void* element, size_t size){
    try
    {
        if (array->size >= array->maxelements) {
            array->maxelements *= 2;
            array->data = realloc(array->data, array->maxelements * size);
        }
        memcpy((char *) array->data + (array->size * size), element, size);
        if(array == NULL || array->data == NULL) throw();
        array->size++;
    } catch{
        error("RUN", "Caught an exception while allocating a data to an array!");
    }
}
