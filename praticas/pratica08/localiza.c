#include <stdio.h>

int main(){

int numeros[10];

for(int i=0; i<10; i++){
    printf("Digite um numero de 1 a 10:");
    scanf("%i", &numeros[i]);
}
int numero = 0;

printf("Tente encontrar um numero de 1 a 10:");
scanf("%i", &numero);

int achou = -1;

for(int i=0; i<10; i++){
    if (numeros[i] == numero) {
        achou = i;
    }
}
if (achou < 0){
    printf("O numero nao foi encontrado");
}else {
    printf("O numero foi encontrado na posicao %i ", achou);
}
    return 0;
}