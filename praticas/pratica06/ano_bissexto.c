#include <stdio.h>
int main()
{

    int ano = 0;

    printf("Digite um ano:");
    scanf("%i", &ano);

    if (ano % 4 == 0 % 100 != 0){
        printf("O ano e bissexto.\n");
    } else {
        printf("O ano nao e bissexto.\n");
    }

    return 0;
}