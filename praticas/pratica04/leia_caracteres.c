#include <stdio.h>

int main(){


// char tecla = 'a';

// printf("Digite uma tecla:");
// scanf("%c", &tecla);
// printf("Voce digitou: %c\n", tecla);

char nome [31];

printf("Digite seu nome:");
scanf("%[^\n]s", nome);
getchar ();
printf("Voce digitou: %s\n", nome);
    return 0;
}