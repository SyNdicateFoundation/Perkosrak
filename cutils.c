#include "./cutils.h"
#include "logger.h"

jmp_buf buffer;
typedef void (*func)(void*);
void foreach(void* array, int size, func func) {
    try
    {
        if(array == NULL || func == NULL)
            throw();
        for (int i = 0; i < size; i++) {
            func((void *) array + i);
        }
    } catch{
        error("RUN", "an error happened while iterating through variables.");
    }
}
void foreachstring(void* array, int size, func func) {
    try{
        if(array == NULL || func == NULL)
            throw();
        for (int i = 0; i < size; i++) {
            func((void*)array + i * 255);
        }
    }catch{
        error("RUN", "an error happened while iterating through variables.");
    }
}