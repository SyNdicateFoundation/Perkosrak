#ifndef CONSOLEPARSER_H
#define CONSOLEPARSER_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include "logger.h"
#include "cutils.h"

extern void* get_value(const char **args, const int argc, const char *arg, const char *type);
#endif
