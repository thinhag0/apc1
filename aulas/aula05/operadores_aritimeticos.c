#include <stdio.h>

int main() {

  //entrada
  int numero1;
  int numero2;
  float numero3;
  
  printf("entre um numero: ");
  int deu_certo =scanf("%i", &numero1);

  printf("entre com outro numero: ");
  deu_certo = scanf("%i", &numero2);

  printf("entre com um numero decimal: ");
  deu_certo = scanf("%f",&numero3);
  
//Processamento
  int soma = numero1 + numero2;
  int subtracao = numero1 - numero2;
  int multiplicacao = numero1 * numero2;
  int divisao = numero1 / numero2;
  float fracao = numero1 / numero3;
  int resto_divisao = numero1 % numero2;
  
  //saida
  printf("%i + %i = %i\n", numero1, numero2, soma);
  printf("%i - %i =%i\n",numero1, numero2, subtracao);
  printf("%i x %i = %i\n",numero1, numero2, multiplicacao);
  printf("%i / %i = %i\n",numero1, numero2, divisao);
  printf("%i / %f = %fn\n",numero1, numero3, fracao);
  printf("%i %% %i = %i\n",numero1, numero2, resto_divisao);
  
  
  return 0;
}