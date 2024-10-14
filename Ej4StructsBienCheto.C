#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct {
    double longitud;
    double latitud;
} TipoPunto;

typedef struct {
    TipoPunto situacion;
    char nombre[50];
} TipoCiudad;


TipoCiudad * crearCiudades(int num_ciudades);
void mostrarCiudades(TipoCiudad* ciudades, int num_ciudades);
void Reordenar(TipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]);


int main() {
    
    int num_ciudades;
    printf("Cuantas ciudades quiere cargar?");
    scanf("%d", &num_ciudades);
    getchar();  // Limpiar el buffer!! si no se hace esto no deja escribir el nombre de la ciudad. INVESTIGAR MAS!
    
    TipoCiudad* ciudades = crearCiudades(num_ciudades);
    mostrarCiudades(ciudades, num_ciudades);
    
    const char nombre_ciudad_referencia[25] = "asd";
    Reordenar(ciudades, num_ciudades, nombre_ciudad_referencia);
    
    // mostrar ciudades luego del reordenamiento
    mostrarCiudades(ciudades, num_ciudades);
    
    return 0;
}


TipoCiudad* crearCiudades(int num_ciudades) {
    
    TipoCiudad* ciudades = (TipoCiudad*) malloc(num_ciudades * sizeof(TipoCiudad));
    
    for (int i = 0; i < num_ciudades; i++){
        
        //ciudades[i]->nombre
        printf("Escriba el nombre de la ciudad numero %d: ", i + 1);
        fgets(ciudades[i].nombre, sizeof(ciudades[i].nombre), stdin);
        

        // para los arreglos de caracteres hay que poner fgets (idealmente) o scanf y en caso de que se lo quiera copiar de otra variable
        // habria que usar strcpy. mientras que si es un char solo se puede copiar normalmente (*legisladores)->nombre = "c" (o pasar la variable)


         // Eliminar el salto de línea si está presente
        ciudades[i].nombre[strcspn(ciudades[i].nombre, "\n")] = 0;
        
        printf("Escriba la longitd de la ciudad: ");
        scanf("%lf", &ciudades[i].situacion.longitud);
        getchar();  // Limpiar el buffer
    
        printf("Escriba la latitud de la ciudad: ");
        scanf("%lf", &ciudades[i].situacion.latitud);
        getchar();  // Limpiar el buffer
    }
    
    return ciudades;
}


void mostrarCiudades(TipoCiudad* ciudades, int num_ciudades){
    for (int i = 0; i < num_ciudades; i++){
        printf("Ciudad: %s \n", ciudades[i].nombre);
        printf("latitud: %.2lf \n", ciudades[i].situacion.latitud);
        printf("longitud: %.2lf \n", ciudades[i].situacion.longitud);
    }
}


void Reordenar(TipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]){
    
    // buscar con un for el indice de la ciudad de referencia
    //ciudad_referencia 
    int ref = -1;
    double distancias[num_ciudades];
    
    
    for (int i = 0; i < num_ciudades; i++){
        ref = i;
        if (strcmp(ciudades[i].nombre, nombre_ciudad_referencia) == 0) {
            ref = i;
            printf("HOLAAAAAAAAAAAA");
            break;
        }
    }
    
    //for (int i = 0; i < num_ciudades; i++){
        //distancias[i] = sqrt(pow(ciudades[ref].situacion.latitud - ciudades[i].situacion.latitud, 2) +
                              //pow(ciudades[ref].situacion.longitud - ciudades[i].situacion.longitud, 2));
    //}
    // ahora hay que reordenar el vector ciudades de ahi dentro sin crear otro vector
    // (para esto hay que implementar un buble sort)
    
    for (int i = 0; i < num_ciudades - 1; i++) {
        for (int j = 0; j < num_ciudades - i - 1; j++) {
            
            double distancia_j = sqrt(pow(ciudades[ref].situacion.latitud - ciudades[j].situacion.latitud, 2) +
                                       pow(ciudades[ref].situacion.longitud - ciudades[j].situacion.longitud, 2));

            double distancia_j_mas_1 = sqrt(pow(ciudades[ref].situacion.latitud - ciudades[j + 1].situacion.latitud, 2) +
                                               pow(ciudades[ref].situacion.longitud - ciudades[j + 1].situacion.longitud, 2));

            if (distancia_j > distancia_j_mas_1) {
                // Intercambiar las ciudades directamente
                TipoCiudad temp_ciudad = ciudades[j];
                ciudades[j] = ciudades[j + 1];
                ciudades[j + 1] = temp_ciudad;
            }
        }
    }

    
    
}


