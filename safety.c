#include "safety.h"

void* sf_alloc(size_t size){
    void* ptr = malloc(size);
    return ptr ? ptr : NULL;
}
void sf_free(void** ptr) {
    if (ptr == NULL) return;

    free(*ptr);
    *ptr = NULL;
}
void sf_strcpy(const char* val, size_t targetsize, char* target){
    if(strlen(val) <= targetsize) strcpy(target, val);
}