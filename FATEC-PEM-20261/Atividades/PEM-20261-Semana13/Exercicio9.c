/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa usa ponteiros e aritmetica de ponteiros pra 
printar um vetor de tras pra frente. A gente mostra o 
vetor na ordem normal na main e depois passa o ponteiro 
do fim do vetor para uma funcao que faz o print invertido.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>

void imprimir_reverso(int *v, int tam){
    
    // Como o ponteiro aponta para depois do ultimo, voltamos 1 posicao
    v--; 
    
    // Anda com o ponteiro de tras pra frente usando o tamanho do vetor
    for(int i = 0; i < tam; i++){
        printf("%d ", *v);
        v--; // volta uma casa na memoria
    }
}

int main(){

    // Vetor com 6 elementos e valores diferentes pra mudar o resultado
    int lista[6] = {10, 25, 40, 55, 70, 85};
    
    // Conta o tamanho do vetor dividindo pelo tipo do dado
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    printf("ORDEM NORMAL:\n");
    for(int i = 0; i < tamanho; i++){
        // printa usando indice direto no vetor
        printf("%d ", lista[i]);
    }

    printf("\n\nORDEM INVERSA:\n");
    
    // Passa o endereço do fim do vetor para a funcao
    imprimir_reverso(lista + tamanho, tamanho);

    printf("\n");
    return 0;
}