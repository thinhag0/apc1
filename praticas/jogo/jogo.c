#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 5
#define MAX_HISTORICO 20
#define TAM_NOME 50

int main() {
    // lista de palavras 
    const char *palavras[MAX_PALAVRAS] = {
        "computador",
        "engenharia",
        "programacao",
        "tecnologia",
        "violao"
    };

    // armazenar o historico de jogos
    typedef struct {
        char nomeJogador[TAM_NOME];
        char palavra[50];
        int venceu;
        int tentativasRestantes;
    } Historico;

    // Historico de jogos
    Historico historico[MAX_HISTORICO];
    int numJogos = 0;

    // Variaveis gerais
    int opcao, tentativasRestantes, letrasDescobertas[50], letrasFaltando;
    char letra, nomeJogador[TAM_NOME];
    const char *palavra;

    // Inicializacao
    srand(time(NULL));

    // Solicitar o nome do jogador
    printf("Digite seu nome: ");
    scanf("%s", nomeJogador);

    do {
        // Exibicao do menu principal
        printf("\n====== MENU ======\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Ver Historico\n");
        printf("3. Sair\n");
        printf("==================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Tente novamente.\n");
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
                printf("Voce tem %d tentativas.\n\n", tentativasRestantes);

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
                        printf("Entrada invalida. Tente novamente.\n");
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
                        
                        printf("Boa! A letra '%c' esta na palavra.\n", letra);
                    } else {
                        tentativasRestantes--;
                        printf("Que pena! A letra '%c' nao esta na palavra. Tentativas restantes: %d\n", letra, tentativasRestantes);
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
                    printf("Parabens, %s! Voce adivinhou a palavra: %s\n", nomeJogador, palavra);
                } else {
                    printf("Suas tentativas acabaram, %s! A palavra correta era: %s\n", nomeJogador, palavra);
                }
                break;
            }
            case 2: {
                // Exibir historico
               
                if (numJogos == 0) {
                    printf("Nenhum jogo foi registrado no historico ainda.\n");
                } else {
                    printf("\n=== Historico de Jogos ===\n");
                    for (int i = 0; i < numJogos; i++) {
                        printf("Jogo %d: Jogador: %s - Palavra: %s - %s - Tentativas restantes: %d\n",
                               i + 1,
                               historico[i].nomeJogador,
                               historico[i].palavra,
                               historico[i].venceu ? "Vitoria" : "Derrota",
                               historico[i].tentativasRestantes);
                    }
                    printf("===========================\n\n");
                }
                break;
            }
            case 3:
                printf("Ate mais, %s!\n", nomeJogador);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
