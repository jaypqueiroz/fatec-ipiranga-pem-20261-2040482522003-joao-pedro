/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa processa um conjunto de 10 dados do
tipo float armazenados em um vetor unidimensional.
O objetivo é calcular a média aritmética, identificar
o maior e o menor valor do conjunto e determinar a 
soma dos elementos que superam a média. A solução foi 
estruturada para otimizar o processamento utilizando 
percorridos eficientes pelo array, sem o auxílio de 
bibliotecas matemáticas externas.

*/

#include <stdio.h>

int main() {
    float valores[10];
    float somaTotal = 0, media, maior, menor, somaAcimaMedia = 0;

    // Leitura dos dados
    printf("Digite 10 valores:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &valores[i]);
        somaTotal += valores[i];
    }

    media = somaTotal / 10;
    maior = valores[0];
    menor = valores[0];

    // Processamento em uma única passagem
    for (int i = 0; i < 10; i++) {
        // Encontrando maior e menor
        if (valores[i] > maior) maior = valores[i];
        if (valores[i] < menor) menor = valores[i];

        // Soma dos valores acima da média
        if (valores[i] > media) {
            somaAcimaMedia += valores[i];
        }
    }

    // Exibição dos resultados
    printf("Media: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n", menor);
    printf("Soma dos valores acima da media: %.2f\n", somaAcimaMedia);

    return 0;
}