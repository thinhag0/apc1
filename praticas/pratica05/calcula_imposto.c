#include <stdio.h>

int main() {
    
    #define icms 17
    #define confis 7.6
    #define pis_pasep 1.65

    float preco_inicial = 0.0f;
    printf("\nDigite o preco inicial:");
    scanf("%f", &preco_inicial);

    float valor_icms = preco_inicial / 100 * icms;
    float valor_confis = preco_inicial / 100 * confis;
    float valor_pis_paseb = preco_inicial / 100 * pis_pasep;

    printf("\n%-23s : R$ %.2f\n", "Preco Inicial", preco_inicial);
    printf("%-23s : R$ %.2f\n", "Valor ICMS (17%)", valor_icms);
    printf("%-23s :R$ %.2f\n", "Valor COFINS (7,6%)", valor_confis);
    printf("%-23s :R$ %.2f\n", "Valor PIS/PASEP (1,65%)", valor_pis_paseb);

    float preco_final = valor_icms + valor_confis + valor_pis_paseb;
    printf("%-23s : R$ %.2f\n","Preco Final", preco_final); 
    return 0;
    }