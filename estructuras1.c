/*

Ejercicio 12: Define una estructura Persona que contenga un nombre,
edad y altura. Crea un programa que permita al usuario ingresar
los datos de una persona y luego los imprima.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // para poder usar strcpy

typedef struct persona {
        char nombre[25];
        int edad;
        float altura;
        } persona;

int main(void)
{
    // crear un objeto
    struct persona Luciano;

    strcpy(Luciano.nombre, "Luciano");
    Luciano.edad = 41;
    Luciano.altura = 1.85;

    printf("La persona es: %s", Luciano.nombre);
    printf("\nSu edad es %d", Luciano.edad);
    printf("\nSu altura es: %f", Luciano.altura);

    printf("elegi un nombre para tu personaje: \n");
    char nombre[25];
    scanf("%s", &nombre);


    strcpy(Luciano.nombre, nombre);
    printf("\nelegi una edad para tu personaje: \n");
    scanf("%d", &Luciano.edad);
    printf("elegi una altura para tu personaje: \n");
    scanf("%f", &Luciano.altura);

    printf("La persona es: %s", Luciano.nombre);
    printf("\nSu edad es %d", Luciano.edad);
    printf("\nSu altura es: %f", Luciano.altura);

    return 0;
}
// notar tambien que se podria crear un nombre para el personaje sin saber cuanto ocupa, se lo guarda en una variable temporal,
// luego se ve la longitud y en base a esta se guarda espacio con un malloc para el nombre y por ultimo se lo asigna a personaje.nombre
// (aumentaria la complejidad de procesamiento pero reduciria el uso de memoria)
/*
En C, una vez que defines una estructura, como struct persona, no puedes
cambiar el nombre del objeto de la estructura en tiempo de ejecuci�n.
En otras palabras, el nombre del objeto de la estructura debe ser conocido
y definido en el c�digo en tiempo de compilaci�n.
*/
