#include "logger.h"

extern char prefix[] = "[Perkosrak]";

void info(char section[], char message[]){
    printf("%s %s INFO >> %s", prefix, section, message);
}

void warn(char section[], char message[]){
    printf("%s %s WARN >> %s", prefix, section, message);
}

void error(char section[], char message[]){
    printf("%s %s ERROR >> %s", prefix, section, message);
}
