#include <stdio.h>

int main(){

int numeros[10];

numeros[0] = 5;
numeros[1] = 7;
numeros[2] = 3;
numeros[3] = 8;
numeros[4] = 1;
numeros[5] = 9;
numeros[6] = 4;
numeros[7] = 2;
numeros[8] = 6;
numeros[9] =10;

//numeros[10] = 11; NAO PODE

for(int i=0; i<10; i++){
    printf("%i,", numeros[i]);
}
    return 0;
}