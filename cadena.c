/* 
 Longitud de una cadena
Objetivo: Escribir un programa que pida al usuario una cadena y
utilice strlen para calcular y mostrar su longitud.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    char cadena[] = "hola como andas?";
    // char* cadena = "hola como andas?";   es una alternativa
    printf("ingrese una cadena");
    
    printf("\nLa longitud de la cadena es %ld", strlen(cadena));
    
    return 0;
}



*/
