#include <stdio.h>

int main(){

char produto [21];
int quantidade = 0;
float valor = 0.0f;

printf("Digite seu produto:");
scanf("%s", &produto);
printf("Digite a quantidade:");
scanf("%i", &quantidade);
printf("Digite o valor:");
scanf("%f", &valor);

printf("=============================\n");
printf("%17s\n","PEDIDO");
printf("=============================\n");
printf("%-15s %-4s %s\n","Produto", "Qtd", "Valor Unit");
printf("%-15s %-4i %.1f\n", produto, quantidade, valor);
printf("=============================\n");

    return 0;
}