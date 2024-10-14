/* 
 Array bidimensional de enteros en el heap
 Declaración y inicialización: Crea un array bidimensional de enteros en el heap y recórrelo.
*/
#include <stdio.h>
#include <stdlib.h>

// cuando se trabaja con arrays no hace falta declararlo antes y luego declarar el puntero
// sino que se crea un array que es un puntero a la primera posicion (apunta al heap eso) y se 
// pone directamente arreglo [no queda muy lindo pArreglo ademas]


int main()
{
    int rows = 3;
    int columns = 3;

    // En ubicaciones no contiguas
    int** pArreglo = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++){
        pArreglo[i] =  (int*)malloc(columns * sizeof(int));
    }
    /* notar que es puntero a puntero y luego para cada primer elemento de una fila asignar memoria para cada elemento (columasn)*/
    
    // para recorrerlo: 

    for (int i = 0; i < rows; i++) {
        int *row_ptr = pArreglo[i]; // Puntero a la fila actual
        for (int j = 0; j < columns; j++) {
            printf("%d ", *(row_ptr + j)); // Acceder con aritmética de punteros
        }
        printf("\n");
    }

    /*lo cual es analogo a:
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", *(pArreglo[i] + j)); // Acceder con aritmética de punteros
        }
        printf("\n");
    }*/


  // para liberarlo es asi:
    for (int i = 0; i < rows; i++) {
        free(pArreglo[i]); // Liberar cada fila
    }
    free(pArreglo); // Liberar el arreglo de punteros




    // En ubicaciones contiguas

// notar que estos lo que hacen es declarar los punteros de las filas y luego eso apunta a los punteros del
// heap, lo cual se hace dentro del bucle for, pero primero se debe asignar espacio para todo, (con eso de 
// pArreglo[0]) y despues lo que hace es, por medio de la aritmetica de punteros ir asignandole en el bucle for
// pero lo que esta adentro del for no es un malloc, no guarda esapcio para nada, solo calcula en donde estaria
// el primer elemento de cada fila

    // Ubicaciones contiguas (metodo 1)
    int** pArreglo3 = (int**) malloc(rows * sizeof(int*));  // igual que antes
    pArreglo3[0] = (int*) malloc(rows * columns * sizeof(int));  
    for(int i=1; i<rows; i++){
        pArreglo3[i] = pArreglo3[0] + columns * i; 
    }
    free(pArreglo3[0]);
    free(pArreglo3);

    int column = 1;
    // ultimo metodo
    int* pArreglo4 = (int*) malloc(rows * columns * sizeof(int));
    *(pArreglo4 + (rows *columns) + column) = 8; \ // se le da un valor a una posicion...
    
    printf("%d", *(pArreglo4 + (rows *columns) + column));
    free(pArreglo4);

    return 0;
}
