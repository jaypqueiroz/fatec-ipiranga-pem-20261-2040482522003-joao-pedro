/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa implementa a ordenacao de um vetor usando o
metodo Selection Sort de forma correta. A ordenacao e feita
por aritmetica de ponteiros e exibe o estado do vetor na 
tela a cada rodada de organizacao.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>

// Funcao simples para inverter duas posicoes usando ponteiros normais
void trocar(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

// Ordenacao Selection Sort real por ponteiros
void selectionSort(int *arr, int n){
    
    // O primeiro laco vai ate a penultima posicao
    for(int i = 0; i < n - 1; i++){
        
        // Assume que o atual e o menor elemento
        int *pMenor = (arr + i);
        
        // Procura se tem alguem menor do que ele no resto do vetor
        for(int j = i + 1; j < n; j++){
            if(*(arr + j) < *pMenor){
                pMenor = (arr + j); // Guarda o ponteiro do novo menor achado
            }
        }
        
        // Se achou um menor diferente do atual, faz a troca
        if(pMenor != (arr + i)){
            trocar((arr + i), pMenor);
        }

        // Mostra o progresso do vetor passo a passo no fim de cada rodada
        for(int k = 0; k < n; k++){
            printf("%2d ", *(arr + k));
        }
        printf("\n");
    }
}

int main(){

    // Vetor com numeros totalmente novos e misturados
    int lista[8] = {45, 12, 8, 91, 33, 5, 62, 21};

    printf("Vetor original:\n");
    for(int i = 0; i < 8; i++){
        printf("%2d ", lista[i]);
    }
    printf("\n\nPassos da ordenacao:\n");

    // Executa o algoritmo
    selectionSort(lista, 8);

    return 0;
}