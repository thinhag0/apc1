#include <stdio.h>
#include <stdlib.h>
int main(){

int numero = 0;

system("color 1F");
do{
printf("Entre com um numero entre 1 e 10:");
scanf("%i", &numero);
while(getchar() != '\n');

if (numero < 1 || numero > 10){
    printf("Numero invalido. Tente novamente!\n");
}
}while(numero < 1 || numero > 10);
    return 0;
}