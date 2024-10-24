#include <stdio.h>

int main(){

    int numero = 0;

    printf("Digite um numero:");
    scanf("%i", &numero);

    int incremento = numero;
    int decremento = numero;

    printf("O pre-incremento do numero %i e %i\n", numero, ++incremento);
    printf("O pre-decremento do numero %i e %i\n", numero, --decremento);

    return 0;
}