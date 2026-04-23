//João Pedro de Queiroz Leite
//RA: 2040482522003
// Análise e Desenvolvimeno de Sistemas - Vespertino
//Objetivo: Desenvolver um programa em C que gerencie o peso de uma frota de 10 pacotes, utilizando ponteiros.
//Data: 22/04/2026

#include <stdio.h>

#define Tam 10

void lerPesos(float *pesos, int n);
void exibirVetor(float *pesos, int n);
void processarCarga(float *pesos, int n);

// le os pesos digitados pelo usuario
void lerPesos(float *pesos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Peso do produto %d: ", i + 1);
        scanf("%f", pesos + i);
    }
}

// mostra todos os produtos e seus pesos
void exibirVetor(float *pesos, int n) {
    for (int i = 0; i < n; i++) {
        printf("Produto %02d: %.2f kg\n", i + 1, *(pesos + i));
    }
}

// calcula a media, define o limite e corrige os que passaram
void processarCarga(float *pesos, int n) {
    float soma = 0, media, limite;

    for (int i = 0; i < n; i++)
        soma += *(pesos + i);

    media  = soma / n;
    limite = media * 1.10; 

    printf("\nMedia: %.2f kg\n", media);
    printf("Limite (+10%%): %.2f kg\n", limite);
    printf("------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (*(pesos + i) > limite) {
            printf("Produto %d (%.2f kg) passou do limite, reduzindo 5%%.\n", i + 1, *(pesos + i));
            *(pesos + i) *= 0.95;
        }
    }
}

int main() {
    float pesos[Tam];

    printf("=== Cadastro de Carga ===\n");
    lerPesos(pesos, Tam);

    printf("\n=== Antes do Processamento ===\n");
    exibirVetor(pesos, Tam);

    processarCarga(pesos, Tam);

    printf("\n=== Depois do Processamento ===\n");
    exibirVetor(pesos, Tam);

    return 0;
}
