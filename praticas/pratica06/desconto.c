#include <stdio.h>

int main(){

float valor_bruto = 0.0f;
float valor_desconto = 0.0f;

printf("Digite o valor bruto:");
scanf("%f", &valor_bruto);


 if (valor_bruto <= 100.00  ){
     valor_desconto == valor_bruto * 0.01f;
 }
    return 0;
}