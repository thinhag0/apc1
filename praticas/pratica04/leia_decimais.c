#include <stdio.h>

int main() {

  float preco = 0.0f;
  printf("Digite um preco: ");
  scanf("%f", &preco);
  printf("Voce digitou: %.2f\n", preco);

  double fracao = 0.0;
  printf("Digite uma fracao: ");
  scanf("%lf", &fracao);
  printf("Voce digitou: %.10f\n", fracao);
  return 0;
}