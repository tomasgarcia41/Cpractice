/* 
Ejercicio 2: Comparación de cadenas
Objetivo: Escribir un programa que compare dos cadenas ingresadas por el 
usuario usando strcmp. Indicar si son iguales, o cuál es mayor alfabéticamente.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char cadena1[] = "apple";
    char cadena2[] = "banana";
    
    int comparacion = strcmp(cadena1, cadena2);
    printf("%d\n\n", strcmp(cadena1,cadena2));
    
    if(comparacion<0){
        printf("la primera cadena es menor");
    }
    else if(comparacion>0){
        printf("la segunda cadena es menor");
    }
    else{
        printf("las cadenas son iguales");
    }    
    return 0;
}
