#include <stdio.h>

int main() {

  int numero = 0;
  printf("Digite um numero inteiro: ");
  scanf("%i", &numero);
  printf("Voce digitou: %i\n", numero);

  int eixo_x = 0;
  int eixo_y = 0;
  printf("Digite as coordenadas de um ponto: ");
  scanf("%i %i", &eixo_x, &eixo_y);
  printf("Voce digitou: %i %i\n", eixo_x, eixo_y);
  return 0;
}