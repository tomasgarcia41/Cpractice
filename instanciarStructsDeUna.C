#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char nombre[50];
} Persona;

void modificarPersona(Persona *p) {
    p->id = 2; // Modificamos el id usando el puntero
    strcpy(p->nombre, "Ruben"); // Usamos strcpy para copiar la cadena
    printf("El nombre de la persona ahora es: %s\n", p->nombre);
}

int main() {
    Persona p1 = {1, "Ana"};
    Persona p2 = {2, "Pedro"};
    
    printf("ID: %d, Nombre: %s\n", p1.id, p1.nombre);
    
    modificarPersona(&p1); // Pasamos la dirección de p1 para modificarla
    
    return 0;
}
