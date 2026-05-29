/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa tem como objetivo converter uma distância fornecida
em centímetros para metros, quilômetros e milhas. Utilizei o tipo 
int para a entrada de dados respeitando o limite definido de 2,1 bilhões,
e os tipos float e double para garantir a precisão necessária nos resultados
decimais. O código inclui uma validação para assegurar que apenas valores
positivos sejam processados, garantindo que o programa lide de forma segura
com dados inválidos antes da realização dos cálculos.
*/

#include <stdio.h>

int main() {
    // Escolha dos tipos:
    // int: usado pois o enunciado define o limite de 2.147.483.647 (tamanho do signed int).
    // float: suficiente para metros, que costuma ter menor precisão decimal que km/milhas.
    // double: usado para km e milhas para garantir alta precisão em cálculos decimais.
    int cm;
    float metros;
    double km, milhas;

    printf("Digite a distancia em centimetros (max 2.147.483.647): ");
    scanf("%d", &cm);

    // Desafio: Verificação de valor positivo
    if (cm < 0) {
        printf("Erro: A distancia deve ser um valor positivo.\n");
    } else {
        // Conversões
        metros = cm / 100.0f;
        km = cm / 100000.0;
        milhas = km / 1.60934;

        printf("Em metros: %.2f m\n", metros);
        printf("Em quilometros: %.5f km\n", km);
        printf("Em milhas: %.5f milhas\n", milhas);
    }

    return 0;
}