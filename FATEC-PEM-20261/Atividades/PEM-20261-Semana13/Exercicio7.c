/*
----------------------------------------------------------
                    FATEC Ipiranga
Disciplina: Programaçao Estruturada e Modular
Prof. Veríssimo
----------------------------------------------------------
O programa usa ponteiro pra andar por um vetor de inteiros.
A gente mostra os enderecos de memoria de cada posicao, 
faz a soma de tudo, calcula a media e acha qual e o 
maior e o menor numero usando o ponteiro pra correr o vetor.

Data - 21/05/2026 
Autor: João Pedro de Queiroz Leite 
RA: 2040482522003
----------------------------------------------------------
*/

#include <stdio.h>

int main(){

    int lista[8] = {12, 5, 27, 4, 19, 8, 33, 15};
    int *pt = lista;

    // Inicializa pegando o valor da primeira posicao sem usar colchetes
    int total = 0, maior = *pt, menor = *pt;
    float media = 0;

    // laco pra rodar os 8 elementos agora
    for(int i = 0; i < 8; i++){

        // mostra o indice, o valor e o endereco atual
        printf("Posicao %d | Valor: %d | Endereco: %p\n", i, *pt, pt);

        // checa maior e menor sem usar aquele monte de else if
        if(*pt < menor) menor = *pt;
        if(*pt > maior) maior = *pt;

        // acumula a soma
        total += *pt;

        // joga o ponteiro pra frente
        pt++;
    }

    // calcula a media dividindo por 8.0 para nao truncar as casas decimais
    media = total / 8.0;

    // mostra os resultados tudo junto
    printf("\n--- RESULTADOS FINAIS ---\n");
    printf("Soma total: %d\nMedia: %.2f\nMenor: %d\nMaior: %d\n", total, media, menor, maior);

    return 0;
}