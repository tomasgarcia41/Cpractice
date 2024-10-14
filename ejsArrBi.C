#include <stdio.h>
#include <stdlib.h>

int n = 4;

int main(void) {
  
    int* arreglo = (int*) malloc(n * n * sizeof(int));


    for (int i = 0; i < n * n; i++) {
        printf("elija un elemento para la posicion %d:", i);
        scanf("%d", (arreglo+i));
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            printf("%d ", *(arreglo + i * n + j)); 
        }
        printf("\n"); 
    }


    
    free(arreglo);

    return 0;
}
