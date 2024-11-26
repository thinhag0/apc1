#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 5
#define MAX_HISTORICO 20
#define TAM_NOME 50

int main() {
    // Lista de palavras para o jogo
    const char *palavras[MAX_PALAVRAS] = {
        "computador",
        "engenharia",
        "programacao",
        "tecnologia",
        "violao"
    };

    // Estrutura para armazenar o histórico de jogos
    typedef struct {
        char nomeJogador[TAM_NOME];
        char palavra[50];
        int venceu;
        int tentativasRestantes;
    } Historico;

    // Histórico de jogos
    Historico historico[MAX_HISTORICO];
    int numJogos = 0;

    // Variáveis gerais
    int opcao, tentativasRestantes, letrasDescobertas[50], letrasFaltando;
    char letra, nomeJogador[TAM_NOME];
    const char *palavra;

    // Inicialização
    srand(time(NULL));

    // Solicitar o nome do jogador
    printf("Digite seu nome: ");
    scanf("%s", nomeJogador);

    do {
        // Exibição do menu principal
        printf("\n====== MENU ======\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Ver Histórico\n");
        printf("3. Sair\n");
        printf("==================\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1: {
                // Iniciar jogo
                tentativasRestantes = MAX_TENTATIVAS;
                memset(letrasDescobertas, 0, sizeof(letrasDescobertas));

                // Selecionar palavra aleatória
                palavra = palavras[rand() % MAX_PALAVRAS];
                letrasFaltando = strlen(palavra);

                printf("\nTente adivinhar a palavra letra por letra.\n");
                printf("Você tem %d tentativas.\n\n", tentativasRestantes);

                // Loop do jogo
                while (tentativasRestantes > 0 && letrasFaltando > 0) {
                    // Exibir a palavra com letras descobertas
                    for (int i = 0; palavra[i] != '\0'; i++) {
                        printf("%c ", letrasDescobertas[i] ? palavra[i] : '_');
                    }
                    printf("\n");

                    // Solicitar uma letra
                    printf("Digite uma letra: ");
                    if (scanf(" %c", &letra) != 1) {
                        printf("Entrada inválida. Tente novamente.\n");
                        while (getchar() != '\n'); // Limpa o buffer
                        continue;
                    }

                    // Verificar acertos
                    int acerto = 0;
                    for (int i = 0; palavra[i] != '\0'; i++) {
                        if (palavra[i] == letra && !letrasDescobertas[i]) {
                            letrasDescobertas[i] = 1;
                            letrasFaltando--;
                            acerto = 1;
                        }
                    }

                    if (acerto) {
                        printf("Boa! A letra '%c' está na palavra.\n", letra);
                    } else {
                        tentativasRestantes--;
                        printf("Que pena! A letra '%c' não está na palavra. Tentativas restantes: %d\n", letra, tentativasRestantes);
                    }
                    printf("\n");
                }

                // Resultado final do jogo
                if (numJogos < MAX_HISTORICO) {
                    Historico jogoAtual;
                    strcpy(jogoAtual.nomeJogador, nomeJogador);
                    strcpy(jogoAtual.palavra, palavra);
                    jogoAtual.venceu = (letrasFaltando == 0);
                    jogoAtual.tentativasRestantes = tentativasRestantes;
                    historico[numJogos++] = jogoAtual;
                }

                if (letrasFaltando == 0) {
                    printf("Parabéns, %s! Você adivinhou a palavra: %s\n", nomeJogador, palavra);
                } else {
                    printf("Suas tentativas acabaram, %s! A palavra correta era: %s\n", nomeJogador, palavra);
                }
                break;
            }
            case 2: {
                // Exibir histórico
                if (numJogos == 0) {
                    printf("Nenhum jogo foi registrado no histórico ainda.\n");
                } else {
                    printf("\n=== Histórico de Jogos ===\n");
                    for (int i = 0; i < numJogos; i++) {
                        printf("Jogo %d: Jogador: %s - Palavra: %s - %s - Tentativas restantes: %d\n",
                               i + 1,
                               historico[i].nomeJogador,
                               historico[i].palavra,
                               historico[i].venceu ? "Vitória" : "Derrota",
                               historico[i].tentativasRestantes);
                    }
                    printf("===========================\n\n");
                }
                break;
            }
            case 3:
                printf("Até mais, %s!\n", nomeJogador);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
