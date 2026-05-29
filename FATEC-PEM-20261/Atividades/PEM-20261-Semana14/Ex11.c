/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa demonstra a manipulação de memória 
através da aritmética de ponteiros em um vetor de 
inteiros, abstendo-se da notação de índices.
O algoritmo realiza a iteração pelo array, soma seus elementos, 
modifica valores in-place e valida a organização contígua dos 
dados na memória ao confirmar que o deslocamento entre endereços 
consecutivos corresponde ao tamanho em bytes do tipo int
*/

#include <stdio.h>

int main() {
    int vetor[6] = {10, 20, 30, 40, 50, 60};
    int *p = vetor; // Inicializa ponteiro com o endereço do primeiro elemento
    int soma = 0;

    printf("Elementos, enderecos e calculos:\n");

    // 1. Percorrer o vetor usando apenas aritmética de ponteiros
    for (int i = 0; i < 6; i++) {
        // Imprime elemento e endereço via %p
        printf("Valor: %d | Endereco: %p\n", *(p + i), (void*)(p + i));
        
        // 2. Calcular a soma
        soma += *(p + i);
    }

    printf("\nSoma dos elementos: %d\n", soma);

    // 3. Dobrar os valores in-place usando desreferenciação
    printf("\nDobrando valores in-place:\n");
    for (int i = 0; i < 6; i++) {
        *(p + i) *= 2; 
        printf("%d ", *(p + i));
    }

    // 4. Confirmar diferença de endereços (sizeof(int))
    printf("\n\nVerificacao de memoria:\n");
    printf("Endereco de p[0]: %p\n", (void*)p);
    printf("Endereco de p[1]: %p\n", (void*)(p + 1));
    printf("Diferenca em bytes (p+1 - p): %ld bytes\n", (long)((char*)(p + 1) - (char*)p));
    printf("Tamanho de int (sizeof): %zu bytes\n", sizeof(int));

    return 0;
}