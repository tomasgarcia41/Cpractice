#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double longitud;
    double latitud;
} tipoPunto;

typedef struct {
    tipoPunto situacion;
    char nombre[50];
} tipoCiudad;

void Reordenar(tipoCiudad **ciudades, int numCiudades, const char nombre_ciudad_referencia[]);
void crearCiudad(tipoCiudad **ciudad); // Cambiar a puntero a puntero

int main() {
    int cantidad;
    printf("Ingrese la cantidad de ciudades: ");
    scanf("%d", &cantidad);
    getchar(); // Limpiar el buffer de entrada

    // Crear un arreglo de punteros a tipoCiudad
    tipoCiudad **ciudades = (tipoCiudad **)malloc(cantidad * sizeof(tipoCiudad *)); // Doble puntero

    for (int i = 0; i < cantidad; i++) {
        crearCiudad(&ciudades[i]); // Pasar la dirección del puntero
        printf("\nCiudad: %s, longitud: %.2lf, latitud: %.2lf.\n\n", 
            ciudades[i]->nombre, 
            ciudades[i]->situacion.longitud, 
            ciudades[i]->situacion.latitud);
    }
    
    // Liberar memoria
    for (int i = 0; i < cantidad; i++) {
        free(ciudades[i]); // Liberar cada ciudad
    }
    free(ciudades); // Liberar el arreglo de punteros

    return 0;
}

void crearCiudad(tipoCiudad **ciudad) {
    *ciudad = (tipoCiudad *)malloc(sizeof(tipoCiudad)); // Asignar memoria para la ciudad
    printf("Ingrese el nombre de la ciudad: ");
    fgets((*ciudad)->nombre, sizeof((*ciudad)->nombre), stdin);
    (*ciudad)->nombre[strcspn((*ciudad)->nombre, "\n")] = '\0'; // Remover el salto de línea

    printf("Ingrese la longitud de la ciudad: ");
    scanf("%lf", &(*ciudad)->situacion.longitud);
    getchar(); // Limpiar el buffer
    printf("Ingrese la latitud de la ciudad: ");
    scanf("%lf", &(*ciudad)->situacion.latitud);
    getchar(); // Limpiar el buffer
}

void Reordenar(tipoCiudad **ciudades, int numCiudades, const char nombreCiudadReferencia[]) {
    // Esta función debería contener la lógica para reordenar las ciudades
    printf("Reordenando ciudades basado en %s...\n", nombreCiudadReferencia);
    
    for (int i = 0; i < numCiudades; i++) {
        // Aquí se debe implementar la lógica de reordenación
        printf("Ciudad: %s\n", ciudades[i]->nombre);
    }

    for (int i = 0; i < numCiudades; i++) {
        // Raiz cuadrada de (x2-x1)^2 + (y2-y1)^2
        double distancia = sqrt(pow((ciudades[i]->situacion.longitud - 0), 2) + 
                                 pow((ciudades[i]->situacion.latitud - 0), 2)); 
        printf("Distancia de la ciudad %s: %.2lf\n", ciudades[i]->nombre, distancia);
    }
}
