#ifndef PERKOSRAK_SAFETY_H
#define PERKOSRAK_SAFETY_H
#include "cutils.h"

void* sf_alloc(size_t size);
void sf_free(void** ptr);
void sf_strcpy(const char* val, size_t targetsize, char* target);
#endif //PERKOSRAK_SAFETY_H
