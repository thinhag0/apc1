#include <stdio.h>

int main() {

int p = 0;
int q = 0;

printf("Digite um numero P:");
scanf("%i", &p);
printf("Digite um numero Q:");
scanf("%i", &q);

printf("%i && %i = %i\n", p, q, p && q);

printf("%i !! %i = %i\n", p, q, p || q);

printf("!%i = %i\n", p, !p);
printf("!%i = %i\n", q, !q);

    return 0;
}