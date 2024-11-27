#include <stdio.h>

int main(){

int n = 0;
int anterior = 0;
int proximo = 1;
printf("Digite um numero:");
scanf("%i", &n);

for(int i=0; i<n; i++) {
printf("%i", proximo);
int auxiliar = proximo;
int proximo = anterior + proximo;
int anterior = auxiliar;
}

    return 0;
}