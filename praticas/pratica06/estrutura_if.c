#include <stdio.h>

int main(){

// int numero = 0;

// printf("Digite um numero inteiro: ");
// scanf("%i", &numero);

// int numero_eh_divisivel_por_2 = numero % 2 == 0;

// if (numero_eh_divisivel_por_2) {
//   printf("O numero %i eh par!\n", numero);
// }else {
//   printf("O numero %i eh impar!\n", numero);
// }

//idade

int idade = 0;

printf("Digite sua idade: ");
scanf("%i", &idade);

if (idade < 16) {
  printf("Voce naum pode votar!\n");
}else {
  if (idade < 18 || idade > 70) {
    printf("Voce pode votar!\n");
}else {
    printf("Voce eh obrigado a votar!\n"); 
  }




    return 0;
}