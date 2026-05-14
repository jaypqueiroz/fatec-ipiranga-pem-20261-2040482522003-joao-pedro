/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Data - 13/05/2026                                      * 
* Autor: João Pedro de Queiroz Leite   2040482522003     *
*--------------------------------------------------------*/

#include <stdio.h>
#include "recursao.h"

// converte pra binario dividindo por 2
void decToBin(int n) {
    if (n > 1) {
        decToBin(n / 2);
    }
    printf("%d", n % 2);
}

// faz a conta de potencia n^e
int potencia(int b, int e) {
    if (e == 0) return 1;
    if (e < 0) return 0; // se o cara colocar negativo da 0
    return b * potencia(b, e - 1);
}

// soma os numeros um por um
int somaDigitos(int num) {
    if (num < 0) num = -num; 
    if (num == 0) return 0;
    return (num % 10) + somaDigitos(num / 10);
}