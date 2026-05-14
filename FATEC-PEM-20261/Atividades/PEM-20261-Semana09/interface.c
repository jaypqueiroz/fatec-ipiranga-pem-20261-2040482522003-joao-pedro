/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Data - 13/05/2026                                      * 
* Autor: João Pedro de Queiroz Leite   2040482522003     *
*--------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "interface.h"
#include "recursao.h"

void interface() {
    int op;
    char texto[256];

    do {
        printf("\n--- CALCULADORA CUCC ---\n");
        printf("1) Binario\n2) Potencia\n3) Somar Digitos\n0) Sair\n");
        printf("Qual opcao: ");
        
        // Verifica se e numero pra nao travar o menu
        if (scanf("%d", &op) != 1) {
            while (getchar() != '\n');
            op = -1;
        }

        if (op == 1) {
            int n1;
            printf("Digite o valor decimal: ");
            scanf("%d", &n1);
            printf("Resultado: ");
            decToBin(n1);
            printf("\n");
        } 
        else if (op == 2) {
            int base, expo;
            printf("Base: ");
            scanf("%d", &base);
            printf("Expoente: ");
            scanf("%d", &expo);
            printf("Deu: %d\n", potencia(base, expo));
        } 
        else if (op == 3) {
            int total = 0;
            printf("Digite os numeros: ");
            getchar(); // limpa o enter anterior
            fgets(texto, 256, stdin);
            
            // varre a string e pega so os numeros
            for (int i = 0; texto[i] != '\0'; i++) {
                if (isdigit(texto[i])) {
                    total += (texto[i] - '0');
                }
            }
            printf("Soma total: %d\n", total);
        }
        else if (op == 0) {
            printf("Fechando o programa...\n");
        }
        else {
            if (op != -1) printf("Opcao errada!\n");
        }
    } while (op != 0);
}