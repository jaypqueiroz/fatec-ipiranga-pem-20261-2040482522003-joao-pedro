/*
-----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
-----------------------------------------------------------
Exercício para inverter os valores de duas variáveis.
Criamos uma função que recebe os ponteiros e faz a inversão
direto na memória usando uma variável de apoio.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
-----------------------------------------------------------
*/

#include <stdio.h>

void trocar(int *a, int *b){

    // Guarda o valor apontado por 'a' na variável auxiliar
    int aux = *a;

    // Atribui o valor apontado por 'b' ao endereço de 'a'
    *a = *b;

    // Atribui o valor antigo de 'a' (guardado em aux) ao endereço de 'b'
    *b = aux;
}

int main(){

    // Valores novos para diferenciar do outro código
    int num1 = 45, num2 = 80;

    // Mostra como estava antes
    printf("[Valores Originais]\nnum1 = %d\nnum2 = %d\n\n", num1, num2);

    // Manda os endereços por referência usando o operador & na chamada
    trocar(&num1, &num2);

    // Mostra o resultado final da inversão
    printf("[Valores Modificados]\nnum1 = %d\nnum2 = %d\n", num1, num2);

    return 0;
}