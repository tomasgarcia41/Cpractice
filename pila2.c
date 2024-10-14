/******************************************************************************
Ejercicio 1: Inversión de una Cadena
Descripción: Escribe un programa que use una pila para invertir una cadena de
caracteres.

Instrucciones:

Lee una cadena del usuario.
Usa una pila para almacenar cada carácter de la cadena.
Desapila los caracteres y construye la cadena invertida.
Imprime la cadena invertida.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
    char caracter; // es lo que almacena
    struct nodo* siguiente;
} Nodo;

typedef struct pila{
    Nodo* cima;
} Pila;

Nodo* crearNodo(char caracter);
Pila* crearPila();
void destruirNodo(Nodo* nodo);
void destruirPila(Pila* pila);
void apilar(Pila* pila, char caracter);
void desapilar(Pila* pila);
void imprimirPila(Pila* pila);

int main()
{   
    char cadena[100];
    char cadenaInvertida[100];
    printf("Ingrese una cadena: ");
    fgets(cadena, sizeof(cadena), stdin);
    
    Pila* pila = crearPila();
    Pila* pilaInvertida = crearPila();
    
    for (int i = 0; i < (strlen(cadena + 1)); i++){
        apilar(pila, cadena[i]);   
    }
    
    imprimirPila(pila);
    

    return 0;
}

Nodo* crearNodo(char caracter){
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->caracter = caracter;
    nodo->siguiente = NULL;
    return nodo;
}

Pila* crearPila(){
    Pila* pila = (Pila*) malloc(sizeof(Pila));
    pila->cima = NULL;
    return pila;
}


void apilar(Pila* pila, char caracter){
    Nodo* nodo = crearNodo(caracter);
    nodo->siguiente = pila->cima;
    pila->cima = nodo;
}
/*
void desapilar(Pila* pila){ // esto es basicamente sacar lo que esta primero
                            // lo cual solo lo podemos hacer si hay algo en la pila
    if (pila->cima != NULL){
        Nodo* eliminar = pila->cima;
        pila->cima = pila->cima->siguiente;
    }
    destruirNodo(eliminar);
    
}
*/

void imprimirPila(Pila* pila) {
    Nodo* actual = pila->cima;
    while (actual != NULL) {
        printf("%c\n", actual->caracter);
        printf("la direccion del siguiente es: %p\n", actual->siguiente);
        actual = actual->siguiente; // Moverse al siguiente nodo
    }
}
