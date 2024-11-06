#include <stdio.h>

int main() {

int nota = 0;

printf("Digite sua nota:");
scanf("%i", &nota);

while (nota < 1 || nota >10){
    printf("Nota invalida. Tente novamente:");
    scanf("%i", &nota);
}
    return 0;
}