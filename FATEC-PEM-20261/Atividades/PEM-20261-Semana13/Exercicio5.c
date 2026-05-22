/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa mexe com vetor e ponteiro.
A gente aponta pro começo do vetor e usa um laço for pra
printar os valores antes e depois de fazer a conta de 
multiplicar por 2 usando a sintaxe do ponteiro.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>

int main(){

    int dados[5] = {10, 20, 30, 40, 50};
    
    // ponteiro apontando pra base do vetor
    int *ptr = dados;

    printf("=== ANTES ===\n");
    for(int i = 0; i < 5; i++){
        // Parenteses obrigatorios para somar o endereço antes de pegar o valor
        printf("%d ", *(ptr + i));
    }

    // Laço que altera os valores direto na memória (Modificação Indireta)
    for(int i = 0; i < 5; i++){
        // Pega o valor do endereço atual, multiplica por 2 e devolve para a memória
        *(ptr + i) = *(ptr + i) * 2;
    }

    printf("\n\n=== DEPOIS ===\n");
    for(int i = 0; i < 5; i++){
        // Printa os valores que já foram modificados no bloco anterior
        printf("%d ", *(ptr + i));
    }

    printf("\n");
    return 0;
}