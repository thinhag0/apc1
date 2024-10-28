#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 5

// Lista de palavras para adivinhar
const char *palavras[MAX_PALAVRAS] = {
    "computador",
    "engenharia",
    "programacao",
    "tecnologia",
    "violao"
};

// Função para exibir a palavra com letras descobertas
void mostrarPalavra(const char *palavra, const int *letrasDescobertas) {
    int len = strlen(palavra);
    for (int i = 0; i < len; i++) {
        if (letrasDescobertas[i]) {
            printf("%c ", palavra[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

// Função principal do jogo
int main() {
    srand(time(NULL));
    int tentativasRestantes = MAX_TENTATIVAS;
    int letrasDescobertas[50] = {0};
    char letra;
    
    // Escolhe uma palavra aleatória
    int indice = rand() % MAX_PALAVRAS;
    const char *palavra = palavras[indice];
    int len = strlen(palavra);
    int letrasFaltando = len;

    printf("Bem-vindo ao jogo de adivinhar palavras do SBT!\n");
    printf("Tente adivinhar a palavra letra por letra.\n");
    printf("Voce tem %d tentativas.\n\n", tentativasRestantes);

    // Loop do jogo
    while (tentativasRestantes > 0 && letrasFaltando > 0) {
        mostrarPalavra(palavra, letrasDescobertas);
        
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        int acerto = 0;
        for (int i = 0; i < len; i++) {
            if (palavra[i] == letra && !letrasDescobertas[i]) {
                letrasDescobertas[i] = 1;
                letrasFaltando--;
                acerto = 1;
            }
        }

        if (acerto) {
            printf("Boa! A letra '%c' esta na palavra.\n", letra);
        } else {
            tentativasRestantes--;
            printf("Que pena! A letra '%c' não esta na palavra. Tentativas restantes: %d\n", letra, tentativasRestantes);
        }
        
        printf("\n");
    }

    // Resultado final
    if (letrasFaltando == 0) {
        printf("Parabens! Você adivinhou a palavra: %s\n", palavra);
    } else {
        printf("Suas tentativas acabaram! A palavra correta era: %s\n", palavra);
    }

    return 0;
}
