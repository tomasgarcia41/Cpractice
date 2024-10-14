#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double longitud;
    double latitud;
} TipoPunto;

typedef struct {
    TipoPunto situacion;
    int num_ciudad;
    char nombre[50];
} TipoCiudad;

void Reordenar(TipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]);

TipoCiudad * crearCiudad();

int main() {
    TipoCiudad * Rosario = crearCiudad();
    printf("%s\n", Rosario->nombre);
    printf("Longitud: %.2lf\n", Rosario->situacion.longitud);
    printf("Latitud: %.2lf\n", Rosario->situacion.latitud);
    printf("%d", Rosario->num_ciudad);
    return 0;
}

TipoCiudad * crearCiudad() {
    TipoCiudad * ciudad = (TipoCiudad*)malloc(sizeof(TipoCiudad));

    printf("Ingresa el nombre de la ciudad: \n");
    
    fgets(ciudad->nombre, sizeof(ciudad->nombre), stdin); 
    
    printf("Ingresa la longitud de la ciudad: \n");
    scanf("%lf", &ciudad->situacion.longitud);   // poner ampersand porque es paso por valor (pq es un dato simple)
    
    printf("Ingresa la latitud de la ciudad: \n");
    scanf("%lf", &ciudad->situacion.latitud); 
    
    printf("Ingresa el num de la ciudad: \n");
    scanf("%d", &ciudad->num_ciudad); 
    
    return ciudad;
}
