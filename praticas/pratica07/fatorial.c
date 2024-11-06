#include <stdio.h>

int main(){

int numero, fatorial = 0;

printf("Digite um numero:");
scanf("%i", &numero);

for (int i=numero; i > 0; i--){
    fatorial = fatorial * i;
}
printf("Numero= %i\nFatorial= %i\n", numero, fatorial);
    return 0;
}