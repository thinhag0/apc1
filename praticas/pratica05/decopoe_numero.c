#include <stdio.h>

int main () {

int numero = 0;

printf("Digite um numero inteiro de 0 a 9999:");
scanf("%i", &numero);

int milhares = numero / 1000;
int centenas = numero % 1000 /100;
int dezenas = numero % 100 / 10;
int unidades = numero % 10;

printf("Milhares: %i\n", milhares);
printf("Centenas: %i\n", centenas);
printf("Dezenas: %i\n", dezenas);
printf("Unidades: %i\n", unidades);
    return 0;
}
