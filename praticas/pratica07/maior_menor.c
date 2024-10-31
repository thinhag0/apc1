#include <stdio.h>

int main(){

int numero, maior, menor = 0;

printf("Digite um numero:");
scanf("%i", &numero);

maior, menor = numero;

while(numero != 0){
    if(numero > maior){
        maior = numero;
    }
    if(numero < menor){
        menor = numero;
    }


 printf("Digite um numero:");
 scanf("%i", &numero);
}
printf("Numero= %i\nMaior= %i\nMenor= %i\n", numero, maior, menor);
    return 0;
}