#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Usar typedef para simplificar el uso de estructuras

// notar que es typedef struct y luego al final se le pone el nombre a la estructura que va a ser un tipo propio
typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;  // Definimos Fecha como un nuevo tipo de datos

typedef struct {
    char nombre[25];
    char apellido[25];
    int edad;
    float altura;
    Fecha fechaDeNacimiento;  // Usar el typedef para la estructura Fecha
} Persona;  // Definimos Persona como un nuevo tipo de datos

int main(void) {
    // Crear un objeto de tipo Persona
    Persona agustin;  // Usamos el typedef para declarar la variable
    
    // Inicializar los campos del objeto Persona
    strcpy(agustin.nombre, "Agustin");  // recordar que strcpy maneja fuente y destino (ahi se almacena "Agustin" en agustin.nombre)
    strcpy(agustin.apellido, "Perez"); 
    agustin.edad = 18;
    agustin.altura = 1.80;
    agustin.fechaDeNacimiento.dia = 15;
    agustin.fechaDeNacimiento.mes = 8;   // Asignar un valor al mes
    agustin.fechaDeNacimiento.anio = 2006; // Asignar un valor al a�o

    // Imprimir la informaci�n del objeto Persona
    printf("Nombre: %s\n", agustin.nombre);
    printf("Edad: %d\n", agustin.edad);
    printf("Altura: %.2f\n", agustin.altura);
    printf("Fecha de Nacimiento: %02d/%02d/%d\n",
           agustin.fechaDeNacimiento.dia,
           agustin.fechaDeNacimiento.mes,
           agustin.fechaDeNacimiento.anio);

    return 0;
}
