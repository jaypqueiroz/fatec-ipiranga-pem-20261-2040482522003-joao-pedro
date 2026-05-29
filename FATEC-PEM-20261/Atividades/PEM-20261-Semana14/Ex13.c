/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este módulo implementa uma biblioteca de operações sobre strings,
organizada em arquivos de interface (.h) e implementação (.c).
O conjunto de funções provê contagem de vogais, inversão de strings
in-place e verificação de palíndromos, demonstrando o uso de 
modularização para reduzir o acoplamento, facilitar a manutenção
e promover a reusabilidade do código em conformidade com o paradigma
imperativo e estruturado.
*/

#include <stdio.h>
#include "string.h"

int main() {
    char s1[] = "Arara";
    char s2[] = "Programacao";

    printf("String: %s\n", s1);
    printf("Vogais: %d\n", contaVogais(s1));
    printf("Palindromo: %s\n", ePalindromo(s1) ? "Sim" : "Nao");
    
    inverteCString(s1);
    printf("Invertida: %s\n\n", s1);

    printf("String: %s\n", s2);
    printf("Vogais: %d\n", contaVogais(s2));
    printf("Palindromo: %s\n", ePalindromo(s2) ? "Sim" : "Nao");

    return 0;
}