/*
Ejercicio 14: Escribe un programa que utilice una estructura anidada para manejar
informaci�n sobre una biblioteca. Define estructuras para Libro y Autor, donde un
autor tiene un nombre y un apellido, y un libro tiene un t�tulo y un autor. Crea varios
libros y permite al usuario buscar un libro por su t�tulo y mostrar la informaci�n del autor.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Autor{
    char nombre[25];
    char apellido[25];
};

struct Libro{
    char titulo[25];
    struct Autor NombreAutor;
};
// IMPORTANTE!!! SE DEBE CREAR ANTES LA ESTRUCTURA DE REFERENCIARLA (SI PONEMOS ANTES LA struct LIBRO ESTARIA MAL)

int main(void){

    //creo objeto
    struct Libro Ulises;
    strcpy(Ulises.titulo, "Ulises");
    strcpy(Ulises.NombreAutor.nombre,"James");
    strcpy(Ulises.NombreAutor.apellido,"Joyce");
    printf("El libro es %s y el autor es %s %s", Ulises.titulo, Ulises.NombreAutor.nombre, Ulises.NombreAutor.apellido);




    return 0;
}
