#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 10
#define MAX_HISTORICO 20

// Lista de palavras para adivinhar
const char *palavras[MAX_PALAVRAS] = {
    "computador",
    "engenharia",
    "programacao",
    "tecnologia",
    "violao",
    "asmodeus"
};

// Estrutura para armazenar o histórico de partidas
typedef struct {
    char palavra[50];
    int venceu;
    int tentativasRestantes;
} Historico;

// Histórico de jogos
Historico historico[MAX_HISTORICO];
int numJogos = 0;

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

// Função para exibir o menu
void exibirMenu() {
    printf("\n====== MENU ======\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Histórico\n");
    printf("3. Sair\n");
    printf("==================\n");
    printf("Escolha uma opcao: ");
}

// Função para exibir o histórico de jogos
void exibirHistorico() {
    if (numJogos == 0) {
        printf("Nenhum jogo foi registrado no historico ainda.\n");
        return;
    }

    printf("\n=== Histórico de Jogos ===\n");
    for (int i = 0; i < numJogos; i++) {
        printf("Jogo %d: Palavra: %s - %s - Tentativas restantes: %d\n",
               i + 1,
               historico[i].palavra,
               historico[i].venceu ? "Vitoria" : "Derrota",
               historico[i].tentativasRestantes);
    }
    printf("===========================\n\n");
}

// Função principal do jogo
void iniciarJogo() {
    srand(time(NULL));
    int tentativasRestantes = MAX_TENTATIVAS;
    int letrasDescobertas[50] = {0};
    char letra;

    // Escolhe uma palavra aleatória
    int indice = rand() % MAX_PALAVRAS;
    const char *palavra = palavras[indice];
    int len = strlen(palavra);
    int letrasFaltando = len;

    printf("Tente adivinhar a palavra letra por letra.\n");
    printf("Voce tem %d tentativas.\n\n", tentativasRestantes);

    // Loop do jogo
    while (tentativasRestantes > 0 && letrasFaltando > 0) {
        mostrarPalavra(palavra, letrasDescobertas);

        printf("Digite uma letra: ");
        if (scanf(" %c", &letra) != 1) {
            printf("Erro na leitura da letra. Tente novamente.\n");
            continue;
        }

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

    // Armazenar o resultado no histórico
    if (numJogos < MAX_HISTORICO) {
        strcpy(historico[numJogos].palavra, palavra);
        historico[numJogos].venceu = (letrasFaltando == 0);
        historico[numJogos].tentativasRestantes = tentativasRestantes;
        numJogos++;
    }

    // Resultado final
    if (letrasFaltando == 0) {
        printf("Parabens! Você adivinhou a palavra: %s\n", palavra);
    } else {
        printf("Suas tentativas acabaram! A palavra correta era: %s\n", palavra);
    }
}

// Função principal com o menu
int main() {
    int opcao;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Erro na leitura da opcao. Tente novamente.\n");
            // Limpa a entrada padrão para evitar loop infinito
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1:
                iniciarJogo();
                break;
            case 2:
                exibirHistorico();
                break;
            case 3:
                printf("Valeu a esperiencia. Fe pra vcs!\n");
                break;
            default:
                printf("So tem 3 opcoes. animal.\n");
        }

    } while (opcao != 3);

    return 0;
}