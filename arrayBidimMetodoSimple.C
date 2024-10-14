#include <stdio.h>
#include <stdlib.h>

int n = 3;

int main(void) {
  
    int* arreglo = (int*) malloc(n * n * sizeof(int));


    for (int i = 0; i < n * n; i++) {
        printf("elija un elemento para la posicion %d: ", i);
        scanf("%d", (arreglo+i));
    }

    for (int i = 0; i < n*n; i++) { 
        if(i%n == 0){printf("\n");}
        printf("%d ", *(arreglo + i)); 
    }


    
    free(arreglo);

    return 0;
}
