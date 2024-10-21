#include <stdio.h>

int main() {

int numero1 = 0;
int numero2 = 0;

printf("Digite um numero:");
scanf("%i", &numero1);
printf("Digite outro numero:");
scanf("%i", &numero2);
//igual
printf("%i e igual %i? %i\n", numero1, numero2, numero1 == numero2);
//diferente
printf("%i e diferente %i? %i\n", numero1, numero2, numero1 != numero2);
//menor
printf("%i e menor que %i? %i\n", numero1, numero2, numero1 < numero2);
//menor ou igual
printf("%i e menor ou igual a %i? %i\n", numero1, numero2, numero1 <= numero2);
//maior
printf("%i e maior que %i? %i\n", numero1, numero2, numero1 > numero2);
//maior ou igual
printf("%i e maior ou igual a %i? %i\n", numero1, numero2, numero1 >= numero2);

    return 0;
}