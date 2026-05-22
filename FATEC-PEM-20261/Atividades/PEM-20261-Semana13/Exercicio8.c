/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa mostra como funciona a aritmetica de ponteiros
com o tipo double. A gente cria dois ponteiros em posicoes
diferentes do vetor, calcula a distancia entre esses ponteiros,
explica como o compilador faz essa conta e depois printa os 
valores no intervalo correspondente.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>

int main(){

    double notas[10] = {1.5, 3.0, 4.5, 6.0, 7.5, 8.0, 9.0, 9.5, 10.0, 10.5};

    // Aponta um ponteiro para o 3.o elemento (index 2) e o outro para o 8.o (index 7)
    double *p_inicio = &notas[2]; 
    double *p_fim = &notas[7];    

    // Calcula a diferenca real entre as posicoes dos ponteiros
    long int diferenca = p_fim - p_inicio;

    printf("Distancia entre os ponteiros (em elementos): %ld\n", diferenca);
    printf("\nValores no intervalo mapeado:\n");

    // Corre o intervalo comparando os enderecos direto, sem depender de index fixo
    while(p_inicio <= p_fim){
        
        printf("-> %.2lf\n", *p_inicio);
        
        // caminha para o endereco do proximo double
        p_inicio++;
    }

    /*
    Explicacao de como o compilador faz esse calculo:
    
    Quando a gente subtrai dois ponteiros do mesmo tipo em C, o resultado 
    nao e a diferenca bruta em bytes na memoria, mas sim a quantidade de 
    elementos que cabem dentro daquele espaco.
    
    Por baixo dos panos, o compilador pega a diferenca real dos enderecos 
    em bytes (ex: se um double ocupa 8 bytes e a diferenca em bytes der 40) 
    e divide essa diferenca pelo tamanho do tipo de dado apontado (sizeof(double)). 
    No nosso caso, 40 bytes divididos por 8 resulta em uma distancia exata 
    de 5 elementos.
    */

    return 0;
}