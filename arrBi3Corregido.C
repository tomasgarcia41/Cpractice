/*Escribe un programa que pida al usuario las dimensiones de una matriz 
(filas y columnas), luego usa malloc para crearla. 
Llena la matriz con números aleatorios y calcula la suma de todos los elementos.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// basicamente se accede a cada posicion usando una mezcla de aritmetica de punteros e indexacion...

int main() {
    int m, n;

    printf("Ingrese la cantidad de filas de la matriz: ");
    scanf("%d", &m);

    printf("Ingrese la cantidad de columnas de la matriz: ");
    scanf("%d", &n);

    // Crear la matriz
    int **matriz = (int**)malloc(m * sizeof(int*));
    matriz[0] = (int*)malloc(m * n * sizeof(int));
    for (int i = 1; i < m; i++) {
        matriz[i] = matriz[0] + n * i;
    }

    size_t tamanioMatriz = m * n * sizeof(int);
    printf("El tamaño de la matriz en bytes es: %zu bytes\n", tamanioMatriz);

    // Rellenar la matriz con números aleatorios
    srand(time(NULL));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(matriz[i] + j) = rand() % 100; // Rellenar con números aleatorios
        }
    }


    int sumatoria = 0;

    // Mostrar la matriz usando aritmética de punteros
    printf("La matriz es:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(matriz[i] + j)); // Atencion a como se accede a los elementos... si se pusiera 
                                                // matriz + i +j mostraria menos elementos
            sumatoria += *(matriz[i] + j);

        }
        printf("\n");
    }

    printf("La suma de todos sus elementos es %d", sumatoria);

    // Liberar la memoria
    free(matriz[0]); 
    free(matriz);    

    return 0;
}
