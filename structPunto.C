/*
Ejercicio 1: Estructura Simple con typedef
Crea una estructura llamada Punto que represente un punto en un plano 2D con las 
coordenadas 'x' y 'y'. Usa typedef para simplificar su uso.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
}Punto;


int main(void){
    
    Punto punto1;
    punto1.x = 5;
    punto1.y = 5;
    
    printf("El punto es: (%d; %d)", punto1.x, punto1.y);
    
    return 0;
}

