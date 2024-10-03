#ifndef PERKOSRAK_CUTILS_H
#define PERKOSRAK_CUTILS_H

#include<setjmp.h>
#include<activation.h>

extern jmp_buf buffer;
#define maxStringLength 255

#define try if (setjmp(buffer) == 0)
#define catch else

#define throw() longjmp(buffer, 1)

typedef void (*func)(void*);

void foreach(void* array, int size, func func);
void foreachstring(void* array, int size, func func);

#endif //PERKOSRAK_CUTILS_H
