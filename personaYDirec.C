/*
Define una estructura Persona que contenga un nombre y una edad, y otra 
estructura Direccion que contenga una calle, ciudad y código postal. La
estructura Persona debe incluir un campo de tipo Direccion.
escribe una funcion que imprima los datos de la persona
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Direccion
struct Direccion {
    int codPostal;
    char calle[25];
    int numero;
};

// Definición de la estructura Persona
struct Persona {
    char nombre[25];
    char apellido[25];
    struct Direccion dirPersona; // Incluye la estructura Direccion
};

// Función para imprimir los datos de la persona
void imprimirDatos(char* nombre, char* apellido, char* dir, int num, int codP) {
    printf("La persona se llama %s %s, su direccion es %s %d y el codigo postal de la ciudad es %d\n", 
           nombre, apellido, dir, num, codP);
}

// Notar que los chars se pasan con punteros...

int main(void) {
    // Crear una instancia de Persona
    struct Persona Pepito;
    
    // Asignar valores a la persona
    strcpy(Pepito.nombre, "Pepito");
    strcpy(Pepito.apellido, "Perez");
    Pepito.dirPersona.codPostal = 2000;
    strcpy(Pepito.dirPersona.calle, "Callao");
    Pepito.dirPersona.numero = 1497;
    
    // Imprimir los datos de la persona
    imprimirDatos(Pepito.nombre, Pepito.apellido, Pepito.dirPersona.calle, 
                  Pepito.dirPersona.numero, Pepito.dirPersona.codPostal);
    
    return 0;
}
