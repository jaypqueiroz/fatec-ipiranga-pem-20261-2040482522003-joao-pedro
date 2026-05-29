/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

O programa tem como objetivo realizar a multiplicação 
de duas matrizes 3x3 de números inteiros, armazenadas 
em memória utilizando a estrutura de vetores de vetores.
A lógica utiliza um laço triplo onde os índices i, j e k
mapeiam a operação de produto escalar necessária para a 
definição algébrica Cij=∑Aik×Bkj. O código garante o
correto alinhamento das matrizes na saída e a integridade 
do cálculo através da inicialização precisa dos acumuladores
parciais.

*/

#include <stdio.h>
#define TAM 3

int main() {
    int A[TAM][TAM], B[TAM][TAM], C[TAM][TAM];
    int i, j, k;

    // Leitura das Matrizes A e B
    printf("Digite os valores da Matriz A (3x3):\n");
    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++) scanf("%d", &A[i][j]);

    printf("Digite os valores da Matriz B (3x3):\n");
    for(i = 0; i < TAM; i++)
        for(j = 0; j < TAM; j++) scanf("%d", &B[i][j]);

    // Multiplicação de Matrizes
    // O loop triplo abaixo implementa a fórmula: C[i][j] = Σ (A[i][k] * B[k][j])
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            C[i][j] = 0; // Inicializa o acumulador antes de somar
            for(k = 0; k < TAM; k++) {
                // A cada passo k, multiplicamos um elemento da linha de A 
                // por um elemento da coluna de B e somamos ao resultado parcial
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Exibição das Matrizes
    printf("\nResultado da Multiplicação (Matriz C):\n");
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}