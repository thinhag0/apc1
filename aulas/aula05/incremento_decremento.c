#include <stdio.h>

int main() {
 
  //entrada
  int numero;
  printf("entre com um numero: ");
  int deu_certo = scanf("%i", &numero);

  //processamento
  //numero = numero + 1;
  int incremento = numero;
  incremento++;//ou ++incremento;
  int pre_incremento = ++incremento;
  int pos_incremento = incremento++;
  //numero =numero _1;
  int decremento = numero;
  decremento--;
  int pre_decremento = --decremento;
  int pos_decremento = decremento--;
  //saida
  printf("Incremento de %i e %i\n", numero, incremento);
  printf("Decremento de %i e %i\n",numero, decremento);
  printf("Pre-incremento de %i e %i\n",numero, pre_incremento);
  printf("Pos-incremento de %i e %i\n",numero, pos_incremento);
  printf("Pre-decremento de %i e %i\n",numero, pre_decremento);
  printf("Pos-decremento de %i e %i\n",numero, pre_decremento);
  

  return 0;
}