/******************************************************************************
Rehacer el ej anterior pero con una funcion para crear matrices dinamicamente
poner lo de NULL para corroborar que todo haya salido correctamente
Luego en lugar de sumarlas transponerlas!
por ultimo, liberar todo con una funcion
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int** crearMatrizUbDiscontiguas(int filas, int columnas);
int** crearMatrizUbContiguasMetodo1(int filas, int columnas);
int* crearMatrizUbContiguasMetodo2(int filas, int columnas);
void rellenarMatrizPunteroDoble(int** matriz, int filas, int columnas);
void rellenarMatrizPunteroDobleUBcontiguas(int** matriz, int filas, int columnas);
void rellenarMatrizPunteroSimple(int* matriz, int filas, int columnas);
void imprimirMatriz(int** matriz, int filas, int columnas);
void imprimirMatrizPuntSimple(int* matriz, int filas, int columnas);
int** transponerMatriz(int** matriz, int filas, int columnas);
void liberarMatrizDoblePuntero(int** matriz, int filas, int columnas);
void liberarMatrizDoblePunteroUbContiguas(int** matriz, int filas, int columnas);
void liberarMatrizPunteroSimple(int* matriz);

int main()
{   
    int m, n;
    printf("Ingrese la cantidad de filas de la matriz: ");
    scanf("%d", &m);
    printf("Ingrese la cantidad de columnas de la matriz: ");
    scanf("%d", &n);
    
    // ubicaciones discontiguas
    int** matriz1 = crearMatrizUbDiscontiguas(m, n);
    rellenarMatrizPunteroDoble(matriz1, m, n);
    imprimirMatriz(matriz1, m, n);
    liberarMatrizDoblePuntero(matriz1, m, n);
    printf("//////////////////////\n");
    

    // ubicaciones contiguas metodo1
    
    int** matriz2 = crearMatrizUbContiguasMetodo1(m, n);
    rellenarMatrizPunteroDobleUBcontiguas(matriz2, m, n);
    imprimirMatriz(matriz2, m, n);
    liberarMatrizDoblePunteroUbContiguas(matriz2, m, n);
    printf("//////////////////////\n");
    

    // ubicaciones contiguas metodo2
    int* matriz3 = crearMatrizUbContiguasMetodo2(m, n);
    rellenarMatrizPunteroSimple(matriz3, m, n);
    imprimirMatrizPuntSimple(matriz3, m, n);
    liberarMatrizPunteroSimple(matriz3);
    printf("//////////////////////\n");
   
    return 0;
}


// notar que para los doble punteros se hace todo igual y es lo mismo para rellenar que para escanear.

int** crearMatrizUbDiscontiguas(int filas, int columnas){
    int** matriz = (int**) malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++){
        matriz[i] = (int*) malloc(columnas * sizeof(int));
    }
    return matriz;
}


int** crearMatrizUbContiguasMetodo1(int filas, int columnas){
    int** matriz = (int**) malloc(filas * sizeof(int*));
    matriz[0] = (int*) malloc(filas * columnas * sizeof(int));
    for (int i = 1; i < filas; i++){
        matriz[i] = matriz[0] + columnas * i;
    }
    return matriz;
}


int* crearMatrizUbContiguasMetodo2(int filas, int columnas){
    int* matriz = (int*) malloc(filas * columnas * sizeof(int));
    return matriz;
}


void rellenarMatrizPunteroDoble(int** matriz, int filas, int columnas){
    for (int i=0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("elija un elemento para la posicion[%d][%d]: ", i, j);
            scanf("%d", (matriz[i] + j));
        }
    }
}


void rellenarMatrizPunteroDobleUBcontiguas(int** matriz, int filas, int columnas){
    for (int i=0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("elija un elemento para la posicion[%d][%d]: ", i, j);
            scanf("%d", (matriz[i] + j));
        }
    }
}


void rellenarMatrizPunteroSimple(int* matriz, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("Elija un elemento para la posicion [%d][%d]: ", i, j);
            scanf("%d", (matriz + i*columnas + j));
        }
    }
    
}


void imprimirMatriz(int** matriz, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("%d ", *(matriz[i] + j));
        }
        printf("\n");
    }
}


void imprimirMatrizPuntSimple(int* matriz, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("%d ", *(matriz + i*columnas + j));
        }
        printf("\n");
    }
}


void liberarMatrizDoblePuntero(int** matriz, int filas, int columnas){
    for (int i = 0; i < filas; i++) {
        free(matriz[i]); // Liberar cada fila
    }
    free(matriz); // Liberar el arreglo de punteros
}


void liberarMatrizDoblePunteroUbContiguas(int** matriz, int filas, int columnas){
    free(matriz[0]);
    free(matriz); 
}

void liberarMatrizPunteroSimple(int* matriz){
    free(matriz);
}
