#include <greetings.h>
#include <stdio.h>
#include "static.h"
#include "dynamic.h"

int main(int argc, char *argv[])
{
    printf("Hello world from programa.c\n");
    greetings();
    printf("Llamando a lib dinámica. Obtengo '%d'\n", dynamic_lib_function("Hola dinámica"));
    printf("Llamando a lib estática. Obtengo '%d'\n", static_lib_function("Hola estática"));

    return 0;
}
