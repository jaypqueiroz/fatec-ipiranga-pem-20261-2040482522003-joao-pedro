/*
------------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
------------------------------------------------------------
Código para testar o funcionamento de ponteiros.
Mostra o valor e o endereço de memória de variáveis do
tipo int, float e char usando ponteiros.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite
RA: 2040482522003
------------------------------------------------------------
*/

#include <stdio.h>

int main(){

    // Variaveis de teste com valores novos
    int x = 84;
    float y = 12.34;
    char d = 'k';

    // Definindo os ponteiros para cada tipo
    int *pX = &x;
    float *pY = &y;
    char *pD = &d;

    // Print do tipo inteiro
    printf("[INT] Valor: %d | Ref: %p | Pointer: %p | Val_Ptr: %d\n\n", 
           x, &x, pX, *pX);

    // Print do tipo float
    printf("[FLOAT] Valor: %f | Ref: %p | Pointer: %p | Val_Ptr: %f\n\n", 
           y, &y, pY, *pY);

    // Print do tipo char
    printf("[CHAR] Valor: %c | Ref: %p | Pointer: %p | Val_Ptr: %c\n", 
           d, &d, pD, *pD);

    return 0;
}