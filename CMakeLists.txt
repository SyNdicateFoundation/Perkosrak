cmake_minimum_required(VERSION 3.27)
project(Perkosrak C)

set(CMAKE_C_STANDARD 11)

add_executable(Perkosrak main.c
        CUtils.h
        CUtils.c
        thread.c
        thread.h
        consoleparser.c
        consoleparser.h
        logger.h
        logger.c)
