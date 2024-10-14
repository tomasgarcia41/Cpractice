// el nombre se fijo con la perspectiva de 0 structs

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Definición de la estructura Libro
typedef struct libro {
    char titulo[25];        // Título del libro
    int copiasDisponibles;  // Copias disponibles
} Libro;

// Definición de la estructura Autor
typedef struct autor {
    char nombre[25];       // Nombre del autor
    char apellido[25];     // Apellido del autor
    Libro* librosEscritos; // Puntero a la lista de libros escritos
    int numLibros;         // Número de libros escritos
} Autor;

int main(void) {
    // Ejemplo de cómo crear un autor y libros

    // Asignar memoria para un autor
    Autor autor;
    strcpy(autor.nombre, "EL");
    strcpy(autor.apellido, "MALIGNO");

    // Suponiendo que el autor tiene 2 libros
    
    printf("INGRESE LA CANTIDAD DE LIBROS: ");
    scanf("%d", &autor.numLibros);
    //autor.numLibros = 5;
    autor.librosEscritos = (Libro*)malloc(autor.numLibros * sizeof(Libro));
    
    for (int i=0; i<autor.numLibros; i++){
        printf("ingrese el nombre del titulo");
        char titulo[25];
        scanf("%s", titulo);
        strcpy(autor.librosEscritos[i].titulo, titulo);
        autor.librosEscritos[i].copiasDisponibles = 3;
        
    }


    // Imprimir información del autor y sus libros
    printf("Autor: %s %s\n", autor.nombre, autor.apellido);
    for (int i = 0; i < autor.numLibros; i++) {
        printf("Libro: %s, Copias disponibles: %d\n", 
               autor.librosEscritos[i].titulo, 
               autor.librosEscritos[i].copiasDisponibles);
    }

    // Liberar memoria
    free(autor.librosEscritos);

    return 0;
}
