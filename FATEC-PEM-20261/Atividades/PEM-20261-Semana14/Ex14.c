/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

O objetivo deste programa é oferecer uma interface de 
menu interativo para a execução de operações matemáticas
fundamentais, incluindo o cálculo de Máximo Divisor Comum
(MDC), potência inteira, verificação de números primos 
e conversão de decimal para binário. O código foi estruturado
de forma modular, onde cada operação é isolada em uma função
dedicada, garantindo alta coesão e baixo acoplamento. 
Além disso, cada função está documentada com seus respectivos
parâmetros, valores de retorno e análise de complexidade 
algorítmica, seguindo boas práticas de engenharia de software
para promover a manutenibilidade e a clareza lógica.
*/

#include <stdio.h>
#include <stdlib.h>

/* Protótipos das funções */
int calcularMDC(int a, int b);
long calcularPotencia(int base, int exp);
int ehPrimo(int n);
char* decimalParaBinario(int n);

int main() {
    int opcao, n1, n2;
    do {
        printf("\n--- Calculadora Modular ---\n");
        printf("1. MDC (Euclides)\n2. Potencia\n3. Verificador Primo\n4. Binario\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: printf("Nums: "); scanf("%d %d", &n1, &n2); printf("MDC: %d\n", calcularMDC(n1, n2)); break;
            case 2: printf("Base/Exp: "); scanf("%d %d", &n1, &n2); printf("Res: %ld\n", calcularPotencia(n1, n2)); break;
            case 3: printf("Num: "); scanf("%d", &n1); printf("%d %s primo.\n", n1, ehPrimo(n1) ? "eh" : "nao eh"); break;
            case 4: printf("Num: "); scanf("%d", &n1); char* bin = decimalParaBinario(n1); printf("Binario: %s\n", bin); free(bin); break;
        }
    } while(opcao != 0);
    return 0;
}

/**
 * MDC (Algoritmo de Euclides)
 * param a, b: inteiros positivos
 * return: O maior divisor comum
 * Complexidade: O(log(min(a, b)))
 */
int calcularMDC(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 * Potencia inteira
 * param base, exp: inteiros
 * return: base elevado a exp
 * Complexidade: O(exp)
 */
long calcularPotencia(int base, int exp) {
    long res = 1;
    for(int i = 0; i < exp; i++) res *= base;
    return res;
}

/**
 * Verificador de número primo
 * param n: inteiro
 * return: 1 se primo, 0 caso contrário
 * Complexidade: O(sqrt(n))
 */
int ehPrimo(int n) {
    if (n < 2) return 0;
    for(int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
    return 1;
}

/**
 * Conversão decimal para binário
 * param n: inteiro
 * return: string representando o binário
 * Complexidade: O(log n)
 */
char* decimalParaBinario(int n) {
    char* bin = (char*)malloc(33 * sizeof(char)); // 32 bits + null terminator
    int i = 31;
    bin[32] = '\0';
    if (n == 0) { bin[31] = '0'; return &bin[31]; }
    while (n > 0) {
        bin[i--] = (n % 2) + '0';
        n /= 2;
    }
    return &bin[i + 1];
}