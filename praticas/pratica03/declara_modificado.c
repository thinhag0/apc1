#include <stdio.h>

int main() {

  long int populacao_mundial = 7800000000L;
  printf("Populacao Mudial: %li\n", populacao_mundial);
  const short int HORA_EM_SEGUNDOS = 3600;
  printf("1 hora em segundos e %i\n", HORA_EM_SEGUNDOS);
  long double precisao_extrema =  3.14159265358979323846L;
  printf("Precisao Extrema: %.20Lf\n", precisao_extrema);
  
  return 0;
}