#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char* URL;

typedef struct nodo {
    URL url;  // es lo que almacena el nodo
    struct nodo* siguiente;
} Nodo;

typedef struct pila {
    Nodo* cima;  // apunta siempre al elemento inicial
} Pila;

Nodo* crearNodo(URL url);
Pila* crearPila();
void destruirNodo(Nodo* nodo);
void destruirPila(Pila* pila);
void apilar(Pila* pila, URL url);
void desapilar(Pila* pila);
URL Cima(Pila* pila);

int main(void)

    return 0;

Nodo* crearNodo(){
    
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    Nodo->url = url;
    Nodo->siguiente = NULL;
    return nodo;
}

void destruirNodo(Nodo* nodo){
    nodo->siguiente = NULL;
    free(nodo);
    
}

void apilar(Pila* pila, URL url){
    Nodo* nodo = crearNodo(url);
    nodo->siguiente = pila->cima;
    pila->cima = nodo;
}

void desapilar(Pila* pila){ // esto es basicamente sacar lo que esta primero
                            // lo cual solo lo podemos hacer si hay algo en la pila
    if (pila->cima != NULL){
        Nodo* eliminar = pila->cima;
        pila->cima = pila->cima->siguiente;
    }
    destruirNodo(eliminar);
    
}

URL cima(){
    if (pila->cima == NULL){
        return NULL;
    }
    else
        return pila->cima->url;
}

Pila* crearPila(){
    Pila* pila = (Pila*) malloc(sizeof(Pila));
    pila->cima = NULL;
    return pila;
}

void destruirPila(Pila* pila){
    while (pila->cima != NULL){
        desapilar(pila);
    }
    free(pila);  // si uno no libera se queda hasta que termina el proceso en el OS
}
