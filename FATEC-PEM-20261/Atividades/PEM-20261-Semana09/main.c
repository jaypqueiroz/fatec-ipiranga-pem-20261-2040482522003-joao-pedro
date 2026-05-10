/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
*Objetivo: Criação de bibliotecas personalizadas         *
aplicando recursividade e modularização                  *
* Data - 13/05/2026                                      * 
* Autor: João Pedro de Queiroz Leite   2040482522003     *
*--------------------------------------------------------*/

#include <stdio.h>
#include "recursao.h"
#include "interface.h"

int main() {
    int opcao, n, base, exp, resultado;

    do {
        exibirMenu();
        opcao = lerOpcao();

        switch (opcao) {
            case 1:
                printf("Digite um numero inteiro positivo: ");
                scanf("%d", &n);
                if (n == 0) {
                    printf("Binario: 0\n");
                } else {
                    printf("Binario: ");
                    decToBin(n);
                    printf("\n");
                }
                break;

            case 2:
                printf("Digite a base: ");
                scanf("%d", &base);
                printf("Digite o expoente (>= 0): ");
                scanf("%d", &exp);
                if (exp < 0) {
                    printf("Expoente invalido!\n");
                    break;
                }
                resultado = potencia(base, exp);
                printf("Resultado: %d\n", resultado);
                break;

            case 3:
                printf("Digite um numero inteiro: ");
                scanf("%d", &n);
                resultado = somaDigitos(n);
                printf("Soma dos digitos: %d\n", resultado);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
