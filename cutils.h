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
#define MAIN int main(){
#define MAINARG int main(int argc, char* argv[]){
#define ENDMAIN return 0;}

#define def(type,name,val) type name = val

#define try if (setjmp(buffer) == 0)
#define catch else

#define throw() longjmp(buffer, 1)

typedef void (*func)(void*);
typedef void (*lambda)(void*);

void foreach(const void* array, int size, func func);
void foreachstring(const void* array, int size, func func);
// cant be used in setjmp if clause idk why
char* format(const char* formatIn, ...);
#endif //PERKOSRAK_CUTILS_H
