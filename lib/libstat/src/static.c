#include "static.h"
#include <stdio.h>
#include <string.h>

int static_lib_function(char* msg)
{
    printf("Soy la lib estática que recibió '%s' y devuelve '%d'\n", msg, strlen(msg));
    return strlen(msg);
}