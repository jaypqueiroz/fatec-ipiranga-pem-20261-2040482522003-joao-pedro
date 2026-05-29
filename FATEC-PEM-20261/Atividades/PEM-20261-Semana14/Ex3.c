/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

O objetivo deste programa é calcular o Índice de Massa Corporal
(IMC) de uma pessoa a partir de dados de peso e altura. O código
implementa uma estrutura de controle de fluxo condicional encadeada
(if-else-if) para classificar o IMC conforme as faixas de referência
estabelecidas. Além disso, o algoritmo realiza uma validação inicial 
das entradas para impedir cálculos com valores nulos ou negativos, 
garantindo a integridade matemática e a robustez do programa.
*/

#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite seu peso (kg): ");
    scanf("%f", &peso);
    printf("Digite sua altura (m): ");
    scanf("%f", &altura);


    // Se o peso ou altura forem <= 0, não podemos prosseguir com o cálculo.
    if (peso <= 0 || altura <= 0) {
        printf("Erro: Valores invalidos para peso ou altura.\n");
    } else {
        // Cálculo do IMC: peso dividido pela altura ao quadrado
        imc = peso / (altura * altura);
        printf("Seu IMC e: %.2f\n", imc);

        // Classificação utilizando if encadeado
        if (imc < 18.5) {
            printf("Classificacao: Abaixo do peso\n");
        } else if (imc < 25.0) {
            printf("Classificacao: Peso normal\n");
        } else if (imc < 30.0) {
            printf("Classificacao: Sobrepeso\n");
        } else {
            printf("Classificacao: Obesidade\n");
        }
    }

    return 0;
}