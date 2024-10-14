#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Alumno{
    char nombre[25];
    int edad;
    float altura;
    struct _Alumno* amigo;
    } Alumno;


int main(void)
{
    Alumno Pedro;
    Alumno Dante;

    strcpy(Pedro.nombre, "Pedro");
    Pedro.edad = 12;
    Pedro.altura = 1.46;
    Pedro.amigo = &Dante;

    return 0;
}
