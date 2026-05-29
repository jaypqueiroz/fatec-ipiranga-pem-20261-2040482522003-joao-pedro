/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

Este programa faz o cálculo da média ponderada de três notas.
Usei variáveis do tipo double para garantir a precisão das notas
e int para os pesos, respeitando o contrato de tipos da linguagem C.
O código lê os dados do usuário, faz o cálculo aplicando a fórmula 
correta e apresenta o resultado formatado com duas casas decimais.
Além disso, incluí o uso do operador sizeof para conferir o tamanho 
de cada tipo em bytes na memória, ajudando a visualizar como o C 
gerencia o espaço que ocupamos
*/
#include <stdio.h>

int main(){

//declaração das notas com decimais
    double n1, n2, n3, media;
//declaração dos pesos inteiros
    int p1, p2, p3;

//leitrua dos valores
    printf("Insira o valor da primeira nota e se peso:");
    scanf("%lf %d", &n1, &p1); //lf é para double é literalmente long float
    printf("Insira o valor da segunda nota e se peso:");
    scanf("%lf %d", &n2, &p2);
    printf("Insira o valor da terceira nota e se peso:");
    scanf("%lf %d", &n3, &p3);

//cálculo da média ponderada
    media = (n1*p1 + n2*p2 + n3*p3) / (p1+ p2+ p3);

//impressão da média para o usuário
    printf("Media: %.2f\n", media);

//impressão dos tamanhos das variáveis
    printf("Tamanho do Double: %lu bytes\n", sizeof(double));
    printf("Tamanho int: %lu bytes\n", sizeof(int));
//lu é para chamar o sizeof
return 0;
}