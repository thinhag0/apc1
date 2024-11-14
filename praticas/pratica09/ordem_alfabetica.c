#include <stdio.h>
#include <string.h>

int main(){

char palavra1[11];
char palavra2[11];

printf("Digite uma palavra:");
scanf("%s", palavra1);
printf("Digite outra palavra:");
scanf("%s", palavra2);

if (strcmp(palavra1, palavra2) >= 0){
printf("Palavra2: %s \n Palavra1: %s", palavra2, palavra1);
}else{
printf("Palavra1: %s \n Palavra2: %s", palavra1, palavra2 );

}
    return 0;
}