/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Data - 13/05/2026                                      * 
* Autor: João Pedro de Queiroz Leite   2040482522003     *
*--------------------------------------------------------*/

#include <stdio.h>
#include "interface.h"

void exibirMenu() {
    printf("\n======================================\n");
    printf("   CUCC - Calculadora Cientifica\n");
    printf("======================================\n");
    printf("  1 - Decimal para Binario\n");
    printf("  2 - Potenciacao\n");
    printf("  3 - Soma dos Digitos\n");
    printf("  0 - Sair\n");
    printf("--------------------------------------\n");
    printf("Opcao: ");
}

int lerOpcao() {
    int op;
    scanf("%d", &op);
    return op;
}
