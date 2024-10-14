/* 
Ejercicio 5: Contar vocales
Objetivo: Escribir un programa que cuente el número de vocales en una cadena 
ingresada por el usuario. Usa strlen para determinar la longitud de la cadena 
y un bucle para contar las vocales.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
 
    char cadena[] = "hola como andas";
    
    int longitud = strlen(cadena);
    printf("%d", longitud);
    
    int contVocales = 0;
    for (int i = 0; i < longitud; i++) {
                                              // importante! usar comillas simples!!!!!!!!!!
        if (*(cadena + i) == 'a' || *(cadena + i) == 'A' || 
            *(cadena + i) == 'e' || *(cadena + i) == 'E' || 
            *(cadena + i) == 'i' || *(cadena + i) == 'I' || 
            *(cadena + i) == 'o' || *(cadena + i) == 'O' || 
            *(cadena + i) == 'u' || *(cadena + i) == 'U') {
            contVocales++;                
        }
        
    }
        
    printf("\nla cantidad de vocales es %d", contVocales);
    

    return 0;
}
