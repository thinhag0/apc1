#include <stdio.h>

int main(){

int nota = 0;

do {
printf("Digite sua nota:");
scanf("%i", &nota);

if(nota < 1 || nota > 10){
    printf("Nota invalida. Tente novamente!");
}
} while (nota < 1 || nota > 10);

    return 0;
}