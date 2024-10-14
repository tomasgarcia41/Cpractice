#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
 char sign;  // Tomara como valores -1, 0 o 1
 unsigned char num_bytes; // si es un byte podra ser hasta 255 (16^2*(1)), 
                        // si son dos va a poder ser hasta 16(2^(2))
 unsigned char * bytes;
 } APint; 


int calcularTamanioDelArray(unsigned char numero){
    printf("ingrese un numero: ");
    if (numero < 0){numero*=-1;};
    
    
    int num_bytes;
    while (numero > 0) {
        numero /= 256; // Desplazar 8 bits a la derecha
        num_bytes++;
    }
    printf("%d", num_bytes);

    return num_bytes;
}


unsigned char* deDecimalArepVectorial(unsigned char num){
    int longitudArray;
    longitudArray = calcularTamanioDelArray(num);
    unsigned char* bytes = (unsigned char*) malloc(longitudArray * sizeof(int));
    
    
    for (int i = 0; i < longitudArray; i++) {
        bytes[i] = num % 256; 
        num /= 256; 
    }
    
    //for(int i = 0; i<num_bytes; i++){
    //    printf("%u", bytes[i]);
    //}
    
    return *bytes;
};
 
 
APint* suma_APint(APint* i1, APint* i2);

int main() {

APint i1;
i1.sign = 1;
i1.num_bytes = 4;


APint i2;
i2.sign = 1;
i2.num_bytes = 4;



    return 0;
}


APint* suma_APint(APint* i1, APint* i2){
    
    
}












