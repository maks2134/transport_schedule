#include "hooks.h"
#include "system.h"
#include "createTransport.h"
#include "findTransport.h"
#include "removeTransport.h"
#include "findstop.h"

void createTransport(){
    ClearConsole();
    create();
}

void findTransport(){
    ClearConsole();
    find();
}

void findStop(){
    ClearConsole();
    finding();
}

void removeTransport(){
    ClearConsole();
    delete();
}