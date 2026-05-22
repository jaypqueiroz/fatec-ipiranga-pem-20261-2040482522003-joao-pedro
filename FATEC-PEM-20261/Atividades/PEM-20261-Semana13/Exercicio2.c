/*
-----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
-----------------------------------------------------------
O programa usa o operador sizeof para verificar o tamanho
em bytes de PONTEIROS para os tipos int, float, double e char.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
-----------------------------------------------------------
*/

#include <stdio.h>

int main(){

    // Variaveis
    int w = 92;
    float x = 45.15;
    char y = 'k';
    double z = 128.75;

    // Ponteiros apontando para as variaveis correspondentes
    int *ptrW = &w;
    float *ptrX = &x;
    char *ptrY = &y;
    double *ptrZ = &z;

    // Mostra o espaco em bytes ocupado PELO PONTEIRO na memoria
    printf("Bytes ocupados pelos PONTEIROS na memoria:\n");
    printf("- Ponteiro para Inteiro: %zu\n- Ponteiro para Float: %zu\n- Ponteiro para Char: %zu\n- Ponteiro para Double: %zu\n", 
           sizeof(ptrW), sizeof(ptrX), sizeof(ptrY), sizeof(ptrZ));

    /*
    Explicação:
    O tamanho do ponteiro NÃO varia com o tipo apontado.
    Por quê? Porque um ponteiro serve apenas para armazenar um endereço de memória.
    O tamanho desse endereço depende exclusivamente da arquitetura do processador e
    do sistema operacional (em sistemas de 64 bits, os endereços têm 64 bits, ou seja, 
    todos os ponteiros ocuparão 8 bytes, seja ele para um char ou para um double).
    */

    return 0;
}