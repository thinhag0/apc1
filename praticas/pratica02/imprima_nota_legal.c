#include <stdio.h>

int main() {

  printf("\n%s\n","===============================");
  printf("\t\t %s\n","Nota Legal");
  printf("%s\n","===============================");
  printf("%-16s %s %s\n","Produto","Qtd","Valor Unit");
  printf("%-16s %-3i %10.2f\n","Camiseta",002,39.99);
  printf("%-16s %-3i %10.2f\n","Calca",001,89.90);
  printf("%-16s %-3i %10.2f\n","Meia Social ",003,19.99);
  printf("%s\n","===============================");
printf("%s %24.2f\n","Total:",229.85);

  
  return 0;
}