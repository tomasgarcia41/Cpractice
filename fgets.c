/******************************************************************************

Leer y Mostrar una Frase
Descripción: Crea un programa que pida al usuario que ingrese 
una frase y luego la muestre en pantalla.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    printf("Ingrese una frase");
    char* frase = (char*) malloc(1000 * sizeof(char));
    
    // fgets(frase, sizeof(frase), stdin);      esto solo mostraria "hola co"
    fgets(frase, 1000, stdin); // Leer la frase
    
    /*
      Cambié fgets(frase, sizeof(frase), stdin); por fgets(frase, 1000, stdin);.
      Esto asegura que fgets lea hasta 999 caracteres (dejando espacio para el \0 al final).
    */

    printf("La frase ingresada es:\n %s", frase);
    
    
    return 0;
}
