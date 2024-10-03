#ifndef PERKOSRAK_LOGGER_H
#define PERKOSRAK_LOGGER_H

#include<stdio.h>

extern char prefix[];

void info(char section[], char message[]);
void warn(char section[], char message[]);
void error(char section[], char message[]);

#endif //PERKOSRAK_LOGGER_H
