#include "hooks.h"
#include "system.h"
#include "createTransport.h"
#include "findTransport.h"
#include "removeTransport.h"

void createTransport(){
    ClearConsole();
    create();
}

void findTransport(){
    ClearConsole();
    find();
}

void removeTransport(){
    ClearConsole();
    delete();
}