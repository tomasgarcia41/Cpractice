/* 
Ejercicio 6: Invertir una cadena
Objetivo: Escribir un programa que invierta una cadena ingresada por el usuario.
Usa un bucle y una nueva cadena para almacenar el resultado.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void) {
 
    char cadena[] = "esta es la cadena";
    char cadenaInvertida[100];
    
    int longitud = strlen(cadena);
    
    for (int i=0; i<longitud; i++){
        *(cadenaInvertida + i) = *(cadena+longitud-1-i);
    }
    
    printf("cadena invertida: %s", cadenaInvertida);

    return 0;
}
