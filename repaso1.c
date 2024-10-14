/******************************************************************************
 Permita al usuario ingresar dos matrices del tamanio que quiera
 y luego sumelas con una funcion suma. imprime todo con una funcion tambien
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(int** matriz, int filas, int columnas);

int** SumarMatrices(int** primerMatriz, int** segundaMatriz, int filas, int columnas);

int main()
{
	int m, n;

	printf("Elija la cantidad de filas de la matriz");
	scanf("%d", &m);
	printf("Elija la cantidad de columnas de la matriz");
	scanf("%d", &n);

	// En ubicaciones no contiguas
	int** matriz1 = (int**)malloc(m * sizeof(int*));
	for(int i=0; i<m; i++) {
		matriz1[i] =  (int*)malloc(n * sizeof(int));
	}


	// Creamos la segunda matriz
	int** matriz2 = (int**) malloc (m * sizeof (int*));
	for (int i=0; i<m; i++) {
		matriz2[i] = (int*) malloc (n * sizeof(int));
	}
	

	// Rellenamos la matriz1
    printf("Ingrese los elementos de la primera matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", (matriz1[i]+j));
        }
    }

    // Rellenamos la matriz2
    printf("Ingrese los elementos de la segunda matriz:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", (matriz2[i]+j));
        }
    }
    
    int **matrizSuma = SumarMatrices(matriz1, matriz2, m, n);
    
    imprimirMatriz(matriz1, m, n);
    printf("\n");
    imprimirMatriz(matriz2, m, n);
    printf("\n");
    imprimirMatriz(matrizSuma, m, n);

	return 0;
}

void imprimirMatriz(int** matriz, int filas, int columnas) {
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}


int** SumarMatrices(int** primerMatriz, int** segundaMatriz, int filas, int columnas){
    // Creamos la matriz suma
	int** matrizSuma = (int**) malloc (filas * sizeof (int*));
	for (int i=0; i<filas; i++) {
		matrizSuma[i] = (int*) malloc (columnas * sizeof(int));
	}
	
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            *(matrizSuma[i]+j) = *(primerMatriz[i]+j) + *(segundaMatriz[i]+j);
        }
    }
    return matrizSuma;
}
    
//}













