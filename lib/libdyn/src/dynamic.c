#include "dynamic.h"
#include <stdio.h>
#include <string.h>

int dynamic_lib_function(char* msg)
{
    printf("Soy la lib dinámica que recibió '%s' y devuelve '%d'\n", msg, strlen(msg));
    return strlen(msg);
}
