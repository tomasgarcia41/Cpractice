#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    double abscisa;
    double ordenada;
} TipoPunto;

typedef struct {
    TipoPunto situacion;
    char nombre[50];
} TipoCiudad;

double distanciaEuclidiana(TipoPunto p1, TipoPunto p2) {
    return sqrt(pow(p1.abscisa - p2.abscisa, 2) + pow(p1.ordenada - p2.ordenada, 2));
}

void Reordenar(TipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]) {
    TipoCiudad referencia;
    int encontrado = 0;

    // Buscar la ciudad de referencia
    for (int i = 0; i < num_ciudades; i++) {
        if (strcmp(ciudades[i].nombre, nombre_ciudad_referencia) == 0) {
            referencia = ciudades[i];
            encontrado = 1;
            break;
        }
    }

    // Si no se encuentra la ciudad de referencia, no hacer nada
    if (!encontrado) {
        printf("Ciudad de referencia no encontrada.\n");
        return;
    }

    // Ordenar las ciudades basándose en la distancia a la ciudad de referencia
    for (int i = 1; i < num_ciudades; i++) {
        TipoCiudad temp = ciudades[i];
        int j = i - 1;
        
        // Mover las ciudades que son más cercanas a la ciudad de referencia
        while (j >= 0 && distanciaEuclidiana(ciudades[j].situacion, referencia.situacion) > 
               distanciaEuclidiana(temp.situacion, referencia.situacion)) {
            ciudades[j + 1] = ciudades[j];
            j--;
        }
        ciudades[j + 1] = temp;
    }

    // Colocar la ciudad de referencia en la primera posición
    for (int i = 0; i < num_ciudades; i++) {
        if (strcmp(ciudades[i].nombre, nombre_ciudad_referencia) == 0) {
            TipoCiudad temp = ciudades[i];
            for (int j = i; j > 0; j--) {
                ciudades[j] = ciudades[j - 1];
            }
            ciudades[0] = temp;
            break;
        }
    }
}
int main() {  // notar como se instancian los vectores de etructuras!!!
    TipoCiudad ciudades[3] = {
        {{1.0, 1.0}, "Granada"},
        {{2.0, 2.0}, "Sevilla"},
        {{0.5, 0.5}, "Malaga"}
    };

    printf("Antes de reordenar:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: (%.2lf, %.2lf)\n", ciudades[i].nombre, ciudades[i].situacion.abscisa, ciudades[i].situacion.ordenada);
    }

    Reordenar(ciudades, 3, "Granada");

    printf("\nDespués de reordenar:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: (%.2lf, %.2lf)\n", ciudades[i].nombre, ciudades[i].situacion.abscisa, ciudades[i].situacion.ordenada);
    }

    return 0;
}
