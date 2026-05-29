/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa realiza a análise e manipulação
de um vetor de tamanho N definido via macro. 
O algoritmo executa a leitura dos dados, identifica 
o maior e menor elemento com seus respectivos índices,
classifica a paridade dos números, gera um vetor 
invertido e implementa uma busca linear para localização 
de elementos específicos. A solução utiliza estruturas de
repetição otimizadas para garantir a eficiência na análise
estatística do conjunto de dados

*/

#include <stdio.h>
#define N 8 // Define o tamanho do vetor como 8

int main() {
    int vetor[N], invertido[N];
    int pares = 0, impares = 0;
    int maior, menor, posMaior = 0, posMenor = 0;
    int busca, encontrado = 0;

    printf("Digite %d números inteiros:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    // Exibição do vetor original
    printf("\nVetor original: ");
    for (int i = 0; i < N; i++) printf("%d ", vetor[i]);

    // Inicialização para busca de maior/menor
    maior = vetor[0];
    menor = vetor[0];

    // Processamento principal (estatísticas e inversão)
    for (int i = 0; i < N; i++) {
        // Estatísticas
        if (vetor[i] > maior) { maior = vetor[i]; posMaior = i; }
        if (vetor[i] < menor) { menor = vetor[i]; posMenor = i; }
        
        if (vetor[i] % 2 == 0) pares++;
        else impares++;

        // Inversão: o elemento na posição i vai para a posição final menos i
        invertido[N - 1 - i] = vetor[i];
    }

    printf("\nMaior: %d (indice %d)\n", maior, posMaior);
    printf("Menor: %d (indice %d)\n", menor, posMenor);
    printf("Pares: %d, Impares: %d\n", pares, impares);

    printf("Vetor invertido: ");
    for (int i = 0; i < N; i++) printf("%d ", invertido[i]);

    // Busca linear
    printf("\nDigite um valor para buscar: ");
    scanf("%d", &busca);
    for (int i = 0; i < N; i++) {
        if (vetor[i] == busca) {
            printf("Valor encontrado no indice %d.\n", i);
            encontrado = 1;
            break; // Para de procurar se achar
        }
    }
    if (!encontrado) printf("Valor nao encontrado.\n");

    return 0;
}