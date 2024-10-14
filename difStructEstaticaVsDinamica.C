/*******************************************************************************

Define una estructura estática:

Crea una estructura llamada Persona que contenga los campos: nombre 
(una cadena de caracteres de 50 caracteres) y edad (un entero).
Declara una variable de tipo Persona y asigna valores a sus campos. 
Luego, imprime los valores.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[25];
    int edad;    
} Persona;


int main()
{
    Persona Jorge;
    strcpy(Jorge.nombre ,"Jorge");
    Jorge.edad = 18;

    // tambien se podria hacer: Persona Jorge = {"Jorge", 18};

    printf("Nombre: %s\nEdad: %d",Jorge.nombre, Jorge.edad);
    return 0;
}

/* Ejercicio 2: Uso de Estructuras Dinámicas
Define y usa una estructura dinámica:

Crea una estructura Estudiante con los campos: nombre (un puntero a cadena
de caracteres) y nota (un flotante).
Usa malloc para asignar memoria para una variable de tipo Estudiante, asigna 
valores y luego imprímelos. No olvides liberar la memoria.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nombre;
    float nota;
} Estudiante;

int main() {
    Estudiante *e = malloc(sizeof(Estudiante));
    e->nombre = malloc(50 * sizeof(char));  // notar como se puede crear espacio para una cosa del tipo de la estructura
    strcpy(e->nombre, "María");
    e->nota = 95.5;

    printf("Nombre: %s, Nota: %.2f\n", e->nombre, e->nota);

    free(e->nombre);
    free(e);
    return 0;
}
