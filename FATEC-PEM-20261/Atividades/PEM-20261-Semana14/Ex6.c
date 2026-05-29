/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa implementa a Conjectura de Collatz,
processando um número inteiro positivo através de um
laço while até que o valor da sequência atinja a unidade.
O algoritmo realiza a verificação de paridade para aplicar
as transformações definidas e contabiliza o número total 
de passos realizados, incluindo uma validação de entrada
para assegurar que apenas valores positivos sejam processados.

*/

#include <stdio.h>

int main() {
    int n, passos = 0;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    // Controle de entrada: só prossegue se n > 0
    if (n <= 0) {
        printf("Erro: O numero deve ser positivo.\n");
    } else {
        printf("Sequencia: %d", n);
        
        // Loop principal: executa enquanto n for diferente de 1
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }
            printf(" -> %d", n);
            passos++;
        }
        
        printf("\nTotal de passos: %d\n", passos);
    }

    return 0;
}