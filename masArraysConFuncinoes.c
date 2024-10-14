/******************************************************************************

Rehacer todo lo de los arrays bidimensionales dinamicos

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int** crearArrayUbDiscontiguas(int filas, int columnas);
int** crearArrayUbContiguas(int filas, int columnas);
int* crearArrayUbContiguasSimple(int filas, int columnas);

void rellenarArrayDoblePuntero(int** array, int filas, int columnas);
void rellenarArraySimple(int* array, int filas, int columnas);

void imprimirArrayDoblePuntero(int** array, int filas, int columnas);
void imprimirArraySimple(int* array, int filas, int columnas);

int* buscarMaximoPorFilasDoblePuntero(int** array, int filas, int columnas);
int* buscarMaximoPorFilasPunteroSimple(int* array, int filas, int columnas);

void liberarArrayUbDiscontiguas(int** array);
void liberarArrayUbContiguas(int** array);
void liberarArrayUbContiguasSimple(int* array);

int main()
{
    int m, n;
    printf("Seleccione la cantidad de filas: ");
    scanf("%d", &m);
    printf("Seleccione la cantidad de columnas: ");
    scanf("%d", &n);
    
    // ubicaciones discontiguas
    int** matriz1 = crearArrayUbDiscontiguas(m, n);
    rellenarArrayDoblePuntero(matriz1, m, n);
    imprimirArrayDoblePuntero(matriz1, m, n);
    int* maximos = buscarMaximoPorFilasDoblePuntero(matriz1, m, n);
    
    // ubicaciones contiguas metodo de doble puntero
    int ** matriz2 = crearArrayUbContiguas(m, n);
    rellenarArrayDoblePuntero(matriz2, m, n);
    imprimirArrayDoblePuntero(matriz2, m, n);
    
    // ubicaciones contiguas metodo de un solo puntero
    int* matriz3 = crearArrayUbContiguasSimple(m, n);
    rellenarArraySimple(matriz3, m, n);
    imprimirArraySimple(matriz3, m, n);
    int* max = buscarMaximoPorFilasPunteroSimple(matriz3, m, n);
    return 0;
}


int** crearArrayUbDiscontiguas(int filas, int columnas){
    int** array = (int**) malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++){
        array[i] = (int*) malloc(columnas * sizeof(int));
    }
    return array;
}


int** crearArrayUbContiguas(int filas, int columnas){
    int** array = (int**) malloc(filas * sizeof(int*));
    array[0] = (int*) malloc(filas * columnas * sizeof(int));
    for (int i = 1; i < filas; i++){
        array[i] = array[0] + columnas * i;    
    }
    return array;
}


int* crearArrayUbContiguasSimple(int filas, int columnas){
    int* array = (int*) malloc(filas * columnas * sizeof(int));
    return array;
}


void rellenarArrayDoblePuntero(int** array, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("Ingrese un elemento para la posicion [%d][%d]: ",i, j);
            scanf("%d", (array[i] + j));
        }
    }
    
    
}


void rellenarArraySimple(int* array, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("Ingrese un elemenot para la posicion [%d][%d]: ", i, j);
            scanf("%d", (array + i * columnas + j));
        }
    }
}


void imprimirArrayDoblePuntero(int** array, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("%d ", *(array[i] + j));
        }
        printf("\n");
    }
}


void imprimirArraySimple(int* array, int filas, int columnas){
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            printf("%d ", *(array + i * columnas + j));
        }
        printf("\n");
    }
}



int* buscarMaximoPorFilasDoblePuntero(int** array, int filas, int columnas){
    int* arrayDeMaximos = (int*) malloc(filas * sizeof(int));

    for (int i = 0; i < filas; i++){
        int maximo = *(array[i]);
        for (int j = 0; j < columnas; j++){
            if (*(array[i] + j) > maximo){
                *(arrayDeMaximos + i) = *(array[i] + j);
                maximo = *(arrayDeMaximos + i);
            }
        }
    }
    for (int i = 0; i < filas; i++){
        printf("El maximo en la fila [%d] es: %d\n", i, *(arrayDeMaximos + i));
    }
    
    return  arrayDeMaximos;
}


int* buscarMaximoPorFilasPunteroSimple(int* array, int filas, int columnas){
    int* arrayDeMaximos = (int*) malloc(filas * sizeof(int));
    for (int i = 0; i < filas; i++){
        int maximo = *(array + i);
        for (int j = 0; j < columnas; j++){
            if (*(array + i * columnas + j) > maximo){
                maximo = *(array + i * columnas + j);
                *(arrayDeMaximos + i) = maximo;
            }
        }
    }
    for (int i = 0; i < filas; i++){
        printf("El maximo en la fila [%d] es: %d\n", i, *(arrayDeMaximos + i));
    }
    
    return  arrayDeMaximos;
}






