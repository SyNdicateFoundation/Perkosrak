#include "consoleparser.h"
#include<stdio.h>
#include<string.h>
#include <stdbool.h>

extern void* get_value(const char **args, const int argc, const char *arg, const char *type){
    for (int i = 0; i < argc - 1; i++) {
        if (strcmp(args[i], arg) != 0) continue;
        if (args[i + 1][0] == '-') return (void *) (bool) 1;
        if (strcmp(type, "string") == 0) return (void*)args[i + 1];
        if (strcmp(type, "int") == 0) return (void*)atoi(args[i + 1]);
        if (strcmp(type, "bool") == 0 != 0) return (void *) (strcmp(args[i + 1], "true") == 0);
    }
    return NULL;
}