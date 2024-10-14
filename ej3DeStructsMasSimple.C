#include <stdio.h>
#include <stdlib.h>
#include <math.h> 


// falta agregar unos ifs para que tenga en cuenta el signo antes de hacer la


typedef struct {
    char sign;               // Tomará como valores -1, 0 o 1
    unsigned char num_bytes; // Hasta 255
    unsigned char *bytes;    // Array que contiene los bytes
} APint;

int calcularTamanioDelArray(unsigned int numero) {
    int num_bytes = 0; 
    if (numero == 0) return 1; 

    while (numero > 0) {
        numero /= 256; // notar que es lo mismo esplazar 8 bits a la derecha
        num_bytes++;
    }
    return num_bytes;
}

unsigned char* deDecimalAreprVectorial(unsigned int num) {
    int longitudArray = calcularTamanioDelArray(num);
    unsigned char* bytes = (unsigned char*)malloc(longitudArray * sizeof(unsigned char));

    for (int i = 0; i < longitudArray; i++) {
        bytes[i] = num % 256; 
        num /= 256; 
    }
    
    // invertir el orden de los bytes para que el byte más significativo esté primero
    for (int i = 0; i < longitudArray / 2; i++) {
        unsigned char temp = bytes[i];
        bytes[i] = bytes[longitudArray - i - 1];
        bytes[longitudArray - i - 1] = temp;
    }
    
    return bytes;
}

unsigned int convertirVector(APint* num) {
    unsigned int resultado = 0; 

    for (int i = 0; i < num->num_bytes; i++) {
        resultado += num->bytes[i] * (unsigned int)pow(256, num->num_bytes - i - 1); // Ajustar el orden
    }

    return resultado;}

APint* suma_APint(APint* i1, APint* i2) {
    unsigned int num1 = convertirVector(i1);
    unsigned int num2 = convertirVector(i2);
    unsigned int suma = num1 + num2;


    // observar como se instancia 
    APint* result = (APint*)malloc(sizeof(APint));
    result->sign = (suma > 0) ? 1 : (suma == 0) ? 0 : -1;
    result->num_bytes = calcularTamanioDelArray(suma);
    result->bytes = deDecimalAreprVectorial(suma);
    
    return result; // Retornar el nuevo APint
}
int main() {
    APint i1;
    i1.sign = 1;
    i1.num_bytes = 2;
    i1.bytes = (unsigned char*)malloc(i1.num_bytes * sizeof(unsigned char));
    i1.bytes[0] = 188; 
    i1.bytes[1] = 2;   // [188, 2] representa al número 700

    APint i2;
    i2.sign = 1;
    i2.num_bytes = 2;
    i2.bytes = (unsigned char*)malloc(i2.num_bytes * sizeof(unsigned char));
    i2.bytes[0] = 44;  
    i2.bytes[1] = 0;   // [44, 0] representa al número 44

    APint* resultado = suma_APint(&i1, &i2);

    // imprimo Resultado
    printf("Resultado de la suma:\n");
    printf("Signo: %d\n", resultado->sign);
    printf("Número de bytes: %u\n", resultado->num_bytes);
    for (int j = 0; j < resultado->num_bytes; j++) {
        printf("bytes[%d]: %u\n", j, resultado->bytes[j]);
    }

    // notar las diferencias en la liberacion de memoria
    free(i1.bytes);
    free(i2.bytes);
    free(resultado->bytes);
    free(resultado);

    return 0;
}
