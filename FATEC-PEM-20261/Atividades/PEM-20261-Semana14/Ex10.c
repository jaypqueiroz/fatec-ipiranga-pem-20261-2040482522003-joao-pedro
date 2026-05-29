/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

O programa tem como objetivo realizar a análise 
de um tabuleiro 4x4 representando um jogo da memória,
estruturado como uma matriz de inteiros. O código é
organizado em funções modulares responsáveis por:
exibir o tabuleiro formatado como grade, verificar 
a simetria dos elementos em relação à diagonal principal
e calcular a soma dos elementos contidos nas diagonais 
principal e secundária, demonstrando o domínio de índices
multidimensionais e estruturação modular.

*/

#include <stdio.h>
#define TAM 4

// Protótipos das funções
void exibirTabuleiro(int mat[TAM][TAM]);
void verificarSimetria(int mat[TAM][TAM]);
void calcularDiagonais(int mat[TAM][TAM]);

int main() {
    // Tabuleiro 4x4 pré-definido para teste
    int tabuleiro[TAM][TAM] = {
        {1, 2, 3, 4},
        {5, 1, 6, 3},
        {7, 8, 2, 5},
        {4, 6, 8, 7}
    };

    exibirTabuleiro(tabuleiro);
    verificarSimetria(tabuleiro);
    calcularDiagonais(tabuleiro);

    return 0;
}

// 1. Exibir grade formatada
void exibirTabuleiro(int mat[TAM][TAM]) {
    printf("--- Tabuleiro ---\n");
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// 2. Verificar simetria em relação à diagonal principal (mat[i][j] == mat[j][i])
void verificarSimetria(int mat[TAM][TAM]) {
    int simetrico = 1;
    for(int i = 0; i < TAM; i++) {
        for(int j = 0; j < TAM; j++) {
            if (mat[i][j] != mat[j][i]) simetrico = 0;
        }
    }
    printf(simetrico ? "\nO tabuleiro eh simetrico." : "\nO tabuleiro NAO eh simetrico.");
}

// 3. Calcular somas das diagonais
void calcularDiagonais(int mat[TAM][TAM]) {
    int somaP = 0, somaS = 0;
    for(int i = 0; i < TAM; i++) {
        somaP += mat[i][i];         // Diagonal Principal: linha == coluna
        somaS += mat[i][TAM - 1 - i]; // Diagonal Secundária: i + j = TAM - 1
    }
    printf("\nSoma Diagonal Principal: %d", somaP);
    printf("\nSoma Diagonal Secundaria: %d\n", somaS);
}