/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa gera e exibe a tabuada completa de 1 a 10, 
utilizando uma estrutura de laços aninhados composta por
for (laço externo) e while (laço interno). Adicionalmente,
implementa um laço do-while para controlar a persistência 
da execução através de uma interação com o usuário ('S'/'N'),
garantindo a execução do processamento ao menos uma vez e 
permitindo a interrupção conforme a escolha do operador.

*/

#include <stdio.h>

int main() {
    char continuar;
    int i, j;

    // do-while: garante que o bloco execute pelo menos uma vez
    do {
        // for: usado porque sabemos exatamente o intervalo (1 a 10)
        for (i = 1; i <= 10; i++) {
            printf("\n--- Tabuada do %d ---\n", i);
            
            j = 1; // inicialização do while
            // while: processa enquanto a condição for verdadeira
            while (j <= 10) {
                printf("%2d x %2d = %3d\n", i, j, i * j);
                j++;
            }
        }

        printf("\nDeseja ver a tabuada novamente? (S/N): ");
        scanf(" %c", &continuar); // O espaço antes de %c ignora quebras de linha

    } while (continuar != 'N' && continuar != 'n');

    return 0;
}