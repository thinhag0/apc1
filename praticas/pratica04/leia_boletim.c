#include <stdio.h>

int main () {

int matricula = 0;
float a1 = 0.0f;
float a2 = 0.0f;
float media =0.0f;

printf("Digite sua matricula:");
scanf("%i", & matricula);
printf("Digite sua nota a1:");
scanf("%f", &a1);
printf("Digite sua nota a2:");
scanf("%f", &a2);

media = a1 + a2;
media = media /2;
printf("Matricula  A1   A2   Media\n");
printf("%-10i %-4.1f %-4.1f %.1f\n", matricula, a1, a2, media);

    return 0;
}