#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 10
#define MAX_HISTORICO 20

const char *palavras[MAX_PALAVRAS] = {
    "computador",
    "engenharia",
    "programacao",
    "tecnologia",
    "violao",
    "asmodeus"
};

typedef struct {
    char palavra[50];
    int venceu;
    int tentativasRestantes;
} Historico;

Historico historico[MAX_HISTORICO];
int numJogos = 0;

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

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

void exibirMenu() {
    limparTela();
    printf("\n====== MENU ======\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Historico\n");
    printf("3. Sair\n");
    printf("==================\n");
    printf("Escolha uma opcao: ");
}

void exibirHistorico() {
    limparTela();
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

void iniciarJogo() {
    limparTela();
    srand(time(NULL));
    int tentativasRestantes = MAX_TENTATIVAS;
    int letrasDescobertas[50] = {0};
    char letra;

    int indice = rand() % MAX_PALAVRAS;
    const char *palavra = palavras[indice];
    int len = strlen(palavra);
    int letrasFaltando = len;

    printf("Tente adivinhar a palavra letra por letra.\n");
    printf("Voce tem %d tentativas.\n\n", tentativasRestantes);

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
            printf("Que pena! A letra '%c' nao esta na palavra. Tentativas restantes: %d\n", letra, tentativasRestantes);
        }

        printf("\n");
    }

    if (numJogos < MAX_HISTORICO) {
        strcpy(historico[numJogos].palavra, palavra);
        historico[numJogos].venceu = (letrasFaltando == 0);
        historico[numJogos].tentativasRestantes = tentativasRestantes;
        numJogos++;
    }

    if (letrasFaltando == 0) {
        printf("Parabens! Voce adivinhou a palavra: %s\n", palavra);
    } else {
        printf("Suas tentativas acabaram! A palavra correta era: %s\n", palavra);
    }
}

int main() {
    int opcao;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Erro na leitura da opcao. Tente novamente.\n");
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
                printf("Valeu a experiencia. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 3);

    return 0;
}
