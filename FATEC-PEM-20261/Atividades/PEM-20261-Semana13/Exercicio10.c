/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programação Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa varre uma matriz 4x4 usando ponteiro simples.
Ele percorre as 16 posicoes seguidas na memoria para achar 
qual e o maior numero guardado e mostra em qual linha e 
coluna esse valor foi encontrado.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>

int main(){

    // Matriz com numeros misturados para o maior nao ser o ultimo
    int dados[4][4] = {
        {10, 42, 15, 23},
        {8,  67, 31, 14},
        {55, 19, 94, 12},
        {38, 46, 27, 60}
    };

    // Ponteiro simples apontando para o primeiro elemento da matriz
    int *ptr = &dados[0][0];

    // Guarda o primeiro valor e as posicoes iniciais
    int maior = *ptr;
    int pos_linha = 0, pos_coluna = 0;

    // Laco unico que roda as 16 posicoes da matriz na memoria
    for(int i = 0; i < 16; i++){

        // Checa se o valor atual apontado e maior
        if(*(ptr + i) > maior){
            maior = *(ptr + i);
            
            // Acha a linha e a coluna fazendo divisao e resto por 4
            pos_linha = i / 4;
            pos_coluna = i % 4;
        }
    }

    // Print mostrando os indices reais da matriz (começando do 0)
    printf("--- RESULTADO DA BUSCA ---\n");
    printf("Maior numero encontrado: %d\n", maior);
    printf("Localizacao -> Linha: %d | Coluna: %d\n", pos_linha, pos_coluna);

    return 0;
}