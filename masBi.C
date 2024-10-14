/*
Usando la matriz creada en el ejercicio anterior, calcula y 
muestra la media de los elementos de cada fila.
*/

#include <stdlib.h>
#include <stdio.h>

int main(void){
    int filas, columnas;

    printf("ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("ingrese la cantidad de columnas: ");
    scanf("%d", &columnas);

    int** matriz = (int**)malloc(filas * sizeof(int*));
    matriz[0] = (int*)malloc(filas * columnas * sizeof(int));
    for (int i=1; i<filas; i++){
        matriz[i] = matriz[0] + columnas * i;
    }
    
    if(matriz == NULL){
        printf("no se ha podido guardar espacio para la matriz\n");
    }
    else{
        printf("La asignacion de espacio ha sido exitosa\n");
    }

    for (int i=0; i<filas; i++){
        for (int j=0; j<columnas; j++){
            printf("elija un elemento para la posicion [%d][%d]: ", i, j);
            scanf("%d", (matriz[i]+j));
        }
    }
    
    float media;
    // imprimo la matriz y calculo la media
    for (int i=0; i<filas; i++){
        for (int j=0; j<columnas; j++){
            printf("%d ", *(matriz[i]+j));
            media += *(matriz[i]+j);
        }
        printf("\n");
    }
    media /= (filas*columnas);
    printf("La media es %f", media);

    return 0;
}
