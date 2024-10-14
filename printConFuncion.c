#include <stdio.h>
#include <stdlib.h>

void imprimirArreglo(int *arr, int tamanio);

int n = 2;

int main(void) {
    int* arreglo = (int*) malloc(n * n * sizeof(int));
    int* arregloTranspuesto = (int*) malloc(n * n * sizeof(int));

    if (arreglo == NULL || arregloTranspuesto == NULL) {  // es una buena practica hacer esto
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Llenar el arreglo
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            printf("Elija un elemento para la posicion [%d][%d]: ", i, j); 
            scanf("%d", (arreglo + i * n + j));
        }
    }

    // Crear el arreglo transpuesto
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            *(arregloTranspuesto + i * n + j) = *(arreglo + j * n + i);
        }
    }



    // Imprimir el arreglo
    imprimirArreglo(arreglo, n*n);

    // Liberar memoria
    free(arreglo);
    free(arregloTranspuesto);

    return 0;
}
void imprimirArreglo(int *arr, int tamanio) {
    int i = 0;
    for (int i=0; i<tamanio; i++){
        if(i%n == 0){printf("\n");};
        printf("%d ", *(arr+i));
    }
   
    printf("\n");
}
