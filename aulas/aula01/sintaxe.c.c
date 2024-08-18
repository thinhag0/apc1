#include <stdio.h> // Inclui a biblioteca padrão de entrada e saída

int main() { // Função principal do programa
    printf("Calculadora !\n");

    //seu código aqui

    //1. entrada
    //levantar meus ingredientes
    //char,int,float
    //variaveis
    //leitura
    int primeiro_numero;
    int segundo_numero;
    primeiro_numero = 5;
    segundo_numero = 6;

    //2. processamento
    //calculo soma,subtracao,multiplicacao,divisao
    int soma = primeiro_numero + segundo_numero;

    //3. saida
    //escrita
    printf("A soma é %i com %i eh %i\n",primeiro_numero,segundo_numero, soma);
    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}