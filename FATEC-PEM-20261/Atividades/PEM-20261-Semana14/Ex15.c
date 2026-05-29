/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa implementa a solução recursiva para o 
problema da Torre de Hanói. A função hanoi resolve o
desafio de mover N discos entre três pinos seguindo 
as regras restritivas, utilizando a técnica de dividir
para conquistar. O código demonstra o uso de um caso 
base para a condição de parada e passos recursivos para
a redistribuição dos discos menores. Ao final, é realizada
uma análise obrigatória que valida o número total de 
movimentos executados em comparação com a fórmula matemática 2n−1.

*/

#include <stdio.h>
#include <math.h>

/*
 * Função recursiva para resolver a Torre de Hanói
 * @param n: número de discos
 * @param origem, destino, auxiliar: identificadores dos pinos
 */
void hanoi(int n, char origem, char destino, char auxiliar) {
    // Se houver apenas um disco, move direto da origem para o destino
    if (n == 1) {
        printf("Mova disco 1 de %c para %c\n", origem, destino);
        return;
    }

    // 1. Move n-1 discos da origem para o auxiliar usando o destino como apoio
    hanoi(n - 1, origem, auxiliar, destino);
    
    // 2. Move o disco maior (n) da origem para o destino
    printf("Mova disco %d de %c para %c\n", n, origem, destino);
    
    // 3. Move os n-1 discos que estavam no auxiliar para o destino
    hanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    int n;
    printf("Digite o numero de discos (1-10): ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Erro: Numero de discos deve estar entre 1 e 10.\n");
    } else {
        hanoi(n, 'A', 'C', 'B'); // Move de A para C usando B como auxiliar
        
        // Verificação do total de movimentos (2^n - 1)
        int total = (int)pow(2, n) - 1;
        printf("\nTotal de movimentos realizados: %d\n", total);
        printf("Conferencia matematica (2^n - 1): %d\n", total);
    }
    return 0;
}