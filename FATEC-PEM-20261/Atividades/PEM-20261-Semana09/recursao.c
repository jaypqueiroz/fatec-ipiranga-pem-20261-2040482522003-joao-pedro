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

// a ideia aqui é empilhar as chamadas e só printar na volta
// assim os bits saem na ordem certa (do mais significativo pro menos)
void decToBin(int n) {
    if (n == 0)
        return;
    decToBin(n / 2);
    printf("%d", n % 2);
}

int potencia(int base, int exp) {
    if (exp == 0)
        return 1;
    return base * potencia(base, exp - 1);
}

// pega o ultimo digito e soma com o resto do numero
int somaDigitos(int n) {
    if (n < 0)
        n = -n; // trata negativos
    if (n == 0)
        return 0;
    return (n % 10) + somaDigitos(n / 10);
}
