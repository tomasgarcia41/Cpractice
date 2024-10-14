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
    
typedef struct{
    char nombre[25];
    int edad;
    float* calificaciones;
    int numCalificaciones; // Cantidad de calificaciones
}Estudiante;

Estudiante* agregarEstudiante();
float promedioDeCalificaciones(Estudiante*);
void imprimirEstudiante(Estudiante*);

    
int main(void) {
        
    
    Estudiante* alumno1 = agregarEstudiante();
    imprimirEstudiante(alumno1);
    
    return 0;
}


Estudiante* agregarEstudiante(){
    Estudiante* instancia = (Estudiante*) malloc(sizeof(Estudiante));
    
    printf("Escriba el nombre del estudiante: ");
    scanf("%s", instancia->nombre);
   
    printf("Escriba la edad del estudiante: ");
    scanf("%d", &instancia->edad);  // como estos son datos por valor hay que poner el ampersand
    
    printf("Escriba el numero de calificaciones a cargar: ");
    
    scanf("%d", &instancia->numCalificaciones);
    instancia->calificaciones = (float*)malloc(instancia->numCalificaciones * sizeof(float));
    
    for (int i = 0; i < instancia->numCalificaciones; i++){
        printf("Escriba la nota de la calificacion numero %d: ", i+1);
        scanf("%f", (instancia->calificaciones+i));
    }
    return instancia;
}


float promedioDeCalificaciones(Estudiante* instancia){
    float promedio = 0; 
    for (int i=0; i < instancia->numCalificaciones; i++){
        promedio += *(instancia->calificaciones + i);
    }
    promedio /= instancia->numCalificaciones;
    printf("El promedio de sus calificaciones es: %f", promedio);
    return promedio;
}


void imprimirEstudiante(Estudiante* instancia){
    printf("Nombre: %s\n", instancia->nombre);
    printf("Edad: %d\n", instancia->edad);
    promedioDeCalificaciones(instancia);
}







