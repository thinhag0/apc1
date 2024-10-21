#include <stdio.h>

int main() {

float nota_a1 = 0.0f;
float nota_a2 = 0.0f;
printf("Digite sua nota A1:");
scanf("%f", &nota_a1);
printf("Digite sua nota A2:");
scanf("%f", &nota_a2);

float media_iesb = nota_a1 * 0.4 + nota_a2 * 0.6;
printf("Sua media e: %f\n", media_iesb);
    return 0;
}