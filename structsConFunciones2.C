/* 
Crea una estructura Estudiante que contenga la siguiente información: nombre, edad
y una lista de calificaciones (puede ser un arreglo dinámico).

1. Crea una función para agregar estudiantes a un arreglo dinámico.
2. Implementa una función para calcular el promedio de calificaciones de cada estudiante.
3. Implementa una función para imprimir la información de todos los estudiantes, incluyendo su promedio.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[25];  // aca no se declara como puntero porque se ponen los corchetes (que es lo mismo)
    int edad;
    float* calificaciones; // notar que se pone un puntero porque se va a crear un array;
    int numDeCalificaciones;
} Estudiante;


Estudiante* agregarEstudiante();
float promedioDeCalificaciones(Estudiante* instancia);
void imprimirInfoEstudiante(Estudiante* instancia);


int main(void){
    
    // Agregamos un Estudiante
    Estudiante* Pedro = agregarEstudiante();
    imprimirInfoEstudiante(Pedro);
    
    return 0;
}


Estudiante* agregarEstudiante(){
    
    Estudiante* instancia = (Estudiante*) malloc(sizeof(Estudiante));

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", instancia->nombre);
    
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &instancia->edad);
    
    printf("Ingrese el numero de calificaciones a cargar: ");
    scanf("%d", &instancia->numDeCalificaciones);
    
    instancia->calificaciones = (float*) malloc(instancia->numDeCalificaciones * sizeof(float));  
    // ojo, aca no se pone el float* antes..
    
    for (int i = 0; i < instancia->numDeCalificaciones; i++){
        printf("Ingrese la calificacion numero %d\n", i+1);
        scanf("%f", (instancia->calificaciones + i));
    }
    
    return instancia;
}


float promedioDeCalificaciones(Estudiante* instancia){
    
    float promedio = 0;
    
    for (int i = 0; i < instancia->numDeCalificaciones; i++){
        promedio += *(instancia->calificaciones + i);
    }
    promedio/= (instancia->numDeCalificaciones);
    
    return promedio;
}


void imprimirInfoEstudiante(Estudiante* instancia){
    // Implementa una función para imprimir la información de todos los estudiantes, incluyendo su promedio.
    
    printf("Nombre: %s\n", instancia->nombre);
    printf("Edad: %d\n", instancia->edad);
    float promedio = promedioDeCalificaciones(instancia);
    printf("Promedio de calificaciones: %.2f\n", promedio);
    printf("Sus calificaciones son: \n");
    for (int i = 0; i < instancia->numDeCalificaciones; i++){
        printf("Calificacion numero %d: %.2f\n", i+1, *(instancia->calificaciones+i));
    }
}



















