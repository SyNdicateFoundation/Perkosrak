#ifndef PERKOSRAK_CUTILS_H
#define PERKOSRAK_CUTILS_H

#include<setjmp.h>
#include "logger.h"
#include <stdarg.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

extern jmp_buf buffer;
#define maxStringLength 255


#define try if (setjmp(buffer) == 0)
#define catch else

#define throw() longjmp(buffer, 1)

typedef void (*func)(void*);

void foreach(const void* array, int size, func func);
void foreachstring(const void* array, int size, func func);
char* format(const char* formatIn, ...);
#endif //PERKOSRAK_CUTILS_H
