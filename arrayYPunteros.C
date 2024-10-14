// Ejercicio 2: Declara un arreglo de enteros y un puntero
// que apunte al primer elemento del arreglo. Usa el puntero para
// recorrer e imprimir todos los elementos del arreglo.

#include <stdio.h>

int main() {
    int arr[5]={1,2,3,4,5};


    /* todo lo siguiente sobra: 
    int *parr;
    parr = arr;  // no hace falta especificar que va a la posicion 0 porque siempre va a la cero.
                    // tampoco hace falta el ampersand
    */
    for(int i=0; i<5; i++)
    {
        printf("\n %d ", *(arr+i));
        printf(" y su direccion es %p", (arr+i));
    }
