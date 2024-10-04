#include "dynamicarray.h"

DynamicArray* make_array(size_t maxelements) {
    DynamicArray* new_array = (DynamicArray*) malloc(sizeof(DynamicArray));
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
void append_array(DynamicArray* array, void* element, size_t size){
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
char* array_toString(DynamicArray* array) {
    try
    {
        if (array == NULL || array->data == NULL || array->size == 0)throw();

        size_t str_size = array->size * 12 + 2;
        char* result = (char*) malloc(str_size);
        strcpy(result, "[");

        for (size_t i = 0; i < array->size; i++) {
            char buffer[12];
            sprintf(buffer, "%d", ((int *) array->data)[i]);

            strcat(result, buffer);

            if (i < array->size - 1)
                strcat(result, ", ");
        }

        strcat(result, "]");
        return result;
    } catch{
        error("RUN", "converting an array to a string resulted in an error.");
        return "[]";
    }
}