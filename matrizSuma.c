#include <stdio.h>
#include <stdlib.h>

int n = 2;

int main(void) {
  
    int* arreglo1 = (int*) malloc(n * n * sizeof(int));
    int* arreglo2 = (int*) malloc(n * n * sizeof(int));
    int* arregloSuma = (int*) malloc(n * n * sizeof(int));

    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            printf("elija un elemento para la posicion[%d][%d]",
            i, j); 
            scanf("%d", (arreglo1 + i * n + j));
        }
    }
    
        
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            printf("elija un elemento para la posicion[%d][%d]",
            i, j); 
            scanf("%d", (arreglo2 + i * n + j));  // se le pasa la ubicacion en memoria no la referencia (el & va para los datos simples)
        }
    }
    

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            printf("%d ", *(arreglo1 + i * n + j)); 
        }
        printf("\n"); 
    }
    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            printf("%d ", *(arreglo2 + i * n + j)); 
        }
        printf("\n"); 
    }
    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            *(arregloSuma + i * n + j) = *(arreglo1 + i * n + j) + *(arreglo2 + i * n + j); 
        }
        printf("\n"); 
    }
    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            printf("%d ", *(arregloSuma + i * n + j)); 
        }
        printf("\n"); 
    }


    return 0;
}
