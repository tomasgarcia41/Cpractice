/*
Ejercicio 13: Modifica la estructura Persona para que incluya otra estructura
Fecha (con d�a, mes y a�o) representando la fecha de nacimiento. Escribe
un programa que permita al usuario ingresar los datos
completos y luego los imprima.
*/

// Directivas:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // para poder usar strcpy

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct Persona{
    char nombre[25];
    int edad;
    float altura;
    struct fecha fechaDeNac;

};

int main(void)
{
    // creo el objeto
    struct Persona Pedro;
    strcpy(Pedro.nombre,"Pedro");
    Pedro.edad = 11;
    Pedro.altura = 1.55;
    Pedro.fechaDeNac.dia = 10;
    Pedro.fechaDeNac.mes = 9;
    Pedro.fechaDeNac.anio = 2023;

    printf("el nombre es %s, la edad es %d, su estatura es %f, su fecha de nacimiento es %d/%d/%d",Pedro.nombre, Pedro.edad, Pedro.altura, Pedro.fechaDeNac.dia, Pedro.fechaDeNac.mes, Pedro.fechaDeNac.anio);

    return 0;
}




