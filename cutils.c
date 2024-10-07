#include "./cutils.h"



jmp_buf buffer;
typedef void (*func)(void*);
void foreach(const void* array, int size, func func) {
    try
    {
        if(array == NULL || func == NULL)
            throw();
        for (int i = 0; i < size; i++) {
            func((void *) array + i);
        }
    } catch{
        error("FE", "an error happened while iterating through variables.");
    }
}
void foreachstring(const void* array, int size, func func) {
    try{
        if(array == NULL || func == NULL)
            throw();
        for (int i = 0; i < size; i++) {
            func((void*)array + i * 255);
        }
    }catch{
        error("FE", "an error happened while iterating through variables.");
    }
}
char* format(const char* fmt, ...) {
    char buffer[maxStringLength];
    va_list args;

    va_start(args, fmt);
    vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    char* result = malloc(strlen(buffer) + 1);

    if(!result || result == NULL) return "NULL";

    strcpy(result, buffer);

    return result;
}