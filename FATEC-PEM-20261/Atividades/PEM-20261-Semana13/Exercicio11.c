/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa usa uma funcao que recebe ponteiros para calcular
as estatisticas de um vetor (soma, media, maior e menor).
As alteracoes sao feitas direto na memoria usando os operadores
de desreferenciacao.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>

void analisar_vetor(int *v, int tam, int *soma, float *media, int *maior, int *menor){

    printf("Elementos do vetor: ");

    for(int i = 0; i < tam; i++){
        // Printa o elemento atual usando aritmetica de ponteiro
        printf("%d ", *(v + i));

        // Acumula a soma direto na memoria
        *soma += *(v + i);

        // Testa se e o maior
        if(*(v + i) > *maior){
            *maior = *(v + i);
        }

        // Testa se e o menor
        if(*(v + i) < *menor){
            *menor = *(v + i);
        }
    }

    // Calcula a media dividindo pelo tamanho recebido no parametro
    *media = (float)*soma / tam;
    printf("\n\n");
}

int main(){

    // Vetor agora com 8 elementos conforme enunciado
    int valores[8] = {14, 3, 27, 8, 45, 19, 52, 11};
    int tam = 8;

    // Variaveis normais para guardar os resultados
    int soma = 0;
    int maior = valores[0]; 
    int menor = valores[0];
    float media = 0.0;

    // Passa o endereco de tudo, incluindo o tamanho
    analisar_vetor(valores, tam, &soma, &media, &maior, &menor);

    // Exibe os relatorios finais
    printf("========== ESTATISTICAS ==========\n");
    printf("Soma total    : %d\n", soma);
    printf("Media obtida  : %.2f\n", media);
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);

    return 0;
}