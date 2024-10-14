/*
Pide al usuario que ingrese las dimensiones de una matriz. Crea la matriz dinámicamente y 
permite al usuario llenarla. Luego, transpón la matriz (intercambia filas por columnas) y muestra el resultado.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int filas, columnas;

    printf("Escoja la cantidad de filas: ");
    scanf("%d", &filas);
    printf("Escoja la cantidad de columnas: ");
    scanf("%d", &columnas);

    // dado que recien se sabra el tamanio en tiempo de ejecucion se debe usar malloc o calloc

    int** bi = (int**)malloc(filas * sizeof(int*));
    bi[0] = (int*)malloc(filas * columnas * sizeof(int));
    for (int i=1; i<filas; i++){
        bi[i] = bi[0] + columnas * i;
    }   

    size_t tamanioEnBytes = filas * columnas * sizeof(int);
    printf("el tamanio del arreglo es de %zu \n", tamanioEnBytes);
    
    int** biTranspuesto = (int**)malloc(columnas * sizeof(int*));
    biTranspuesto[0] = (int*)malloc(columnas * filas * sizeof(int));
    for (int i=1; i<columnas; i++){
        biTranspuesto[i] = biTranspuesto[0] + filas * i;
    }
    
    // Rellenar bi
    for (int i=0; i<filas; i++){
        for (int j=0; j<columnas; j++){
            printf("elija un elemento para la posicion [%d][%d]: ", i, j);
            scanf("%d", (bi[i] + j));  // OJO!! ACA NO SE PONE EL *, YA QUE SIEMPRE
                                        // QUE SE ACCEDE A UN ARREGLO SE ACCEDE CON PUNTERO!
        }
    }
    
    // Imprimir bi y rellenar biTranspuesto
    for (int i=0; i<filas; i++){
        for (int j=0; j<columnas; j++){
            printf("%d ", *(bi[i] + j));
            *(biTranspuesto[j] + i) = *(bi[i] + j);
        }
        printf("\n");
    }
    
    printf("\n");
    
    // Imprimir biTranspuesto
    for (int i=0; i<columnas; i++){
        for (int j=0; j<filas; j++){
            printf("%d ", *(biTranspuesto[i] + j));
        }
        printf("\n");
    }
    
    

    free(bi[0]);
    free(bi);
    free(biTranspuesto[0]);
    free(biTranspuesto);

    return 0;
}
