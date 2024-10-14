#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _Alumno{
    char nombre[25];
    int edad;
    float altura;
    struct _Alumno* amigo;
}Alumno;


int main(void){

    Alumno Juan;
    Alumno Pedro;
    Alumno Fran;

    strcpy(Juan.nombre, "Juan");
    strcpy(Pedro.nombre, "Pedro");
    strcpy(Fran.nombre, "Fran");
    Pedro.edad = 16;
    Juan.edad = 14;
    Juan.altura = 1.68;
    Fran.edad = 15;
    Fran.altura = 1.7;
    Juan.amigo = &Pedro;
    Pedro.amigo = &Fran;

    printf("El nombre es %s, su edad es %d, su altura es %f, su mejor amigo es %s",Juan.nombre, Juan.edad ,Juan.altura, Juan.amigo->nombre);
    printf("\n la edad del amigo de Juan es %d", Juan.amigo->edad);
    printf("\n la edad del amigo de Pedro es %d", Pedro.amigo->edad);
    printf("\n la edad del amigo de Pedro es %d", Fran.edad);
    return 0;
}
