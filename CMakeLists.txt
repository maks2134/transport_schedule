cmake_minimum_required(VERSION 3.28)
project(transport_schedule C)

set(CMAKE_C_STANDARD 11)

add_executable(transport_schedule main.c
        system.c
        system.h
        quest.c
        quest.h
        hooks.c
        hooks.h
        createTransport.c
        createTransport.h
        findTransport.c
        findTransport.h
        schedule.h
        removeTransport.c
        removeTransport.h
        findstop.c
        findstop.h
)
