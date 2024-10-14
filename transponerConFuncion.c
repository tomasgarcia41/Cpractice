#include <stdio.h>
#include <stdlib.h>

void imprimirArreglo(int *arr, int filas, int columnas);
int* transponerArreglo(int *arr, int filas, int columnas); 



int main(void) {
    
    
    int filas = 2;
    int columnas = 3;
    
    int* arreglo = (int*) malloc(filas * columnas * sizeof(int));
    int* arregloTranspuesto = (int*) malloc(columnas * filas * sizeof(int));



    // Llenar el arreglo
    for (int i = 0; i < filas; i++) { 
        for (int j = 0; j < columnas; j++) {
            printf("Elija un elemento para la posicion [%d][%d]: ", i, j); 
            scanf("%d", (arreglo + i * columnas + j));
        }
    }



    // Imprimir el arreglo
    imprimirArreglo(arreglo, filas, columnas);
    int* arregloTr = transponerArreglo(arreglo, filas, columnas);
    imprimirArreglo(arregloTr, columnas, filas);
    

    return 0;
}
void imprimirArreglo(int *arr, int filas, int columnas) {
    int i = 0;
    for (int i=0; i< filas*columnas; i++){
        if(i%columnas == 0){printf("\n");};
        printf("%d ", *(arr+i));
    }
   
    printf("\n");
}


int* transponerArreglo(int *arr, int filas, int columnas) {
    int *arregloTranspuesto = (int*) malloc(filas * columnas * sizeof(int));
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas ; j++){
            *(arregloTranspuesto + j*filas + i) = *(arr + j + i*columnas);
        }
    }
    
    
    return arregloTranspuesto;
}



