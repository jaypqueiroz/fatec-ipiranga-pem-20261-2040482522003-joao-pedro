/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

O objetivo deste programa é implementar e comparar 
algoritmos de busca e processamento de dados baseados 
no paradigma da recursividade estritamente declarada.
O algoritmo utiliza a estratégia de dividir para 
conquistar para realizar a soma de elementos do vetor
através de divisões sucessivas do intervalo, e 
emprega uma busca linear recursiva para localizar 
elementos específicos. O programa visa também mensurar
o custo computacional da recursão, registrando a 
quantidade de chamadas e a profundidade máxima atingida
na pilha de execução, permitindo uma análise prática
sobre a eficiência e o comportamento dos algoritmos
recursivos em comparação aos métodos iterativos tradicionais.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variáveis globais para monitoramento conforme exigido
int chamadasRec = 0, profMax = 0;

/* * Função: buscaRec
 * Objetivo: Encontrar o índice de uma chave em um vetor.
 * Caso Base: Se o índice atingir n, a chave não existe (-1). Se v[i] == chave, retorna o índice.
 * Passo Recursivo: Chama a função para o próximo índice (i+1).
 */
int buscaRec(int *v, int n, int chave, int i, int prof) {
    chamadasRec++;
    if (prof > profMax) profMax = prof;

    // Caso Base
    if (i == n) return -1;
    if (v[i] == chave) return i;

    // Passo Recursivo
    return buscaRec(v, n, chave, i + 1, prof + 1);
}

/* * Função: somaRec
 * Objetivo: Somar elementos usando divisão sucessiva (estratégia de dividir para conquistar).
 * Caso Base: Se o intervalo for de um único elemento, retorna ele mesmo.
 * Passo Recursivo: Divide o vetor ao meio, soma cada metade recursivamente.
 */
int somaRec(int *v, int ini, int fim, int prof) {
    chamadasRec++;
    if (prof > profMax) profMax = prof;

    // Caso Base
    if (ini == fim) return v[ini];

    // Passo Recursivo
    int meio = (ini + fim) / 2;
    return somaRec(v, ini, meio, prof + 1) + somaRec(v, meio + 1, fim, prof + 1);
}

int main() {
    srand(time(NULL));
    int v[12], chave;

    for (int i = 0; i < 12; i++) v[i] = rand() % 50;

    printf("Vetor: ");
    for (int i = 0; i < 12; i++) printf("%d ", v[i]);

    // Soma
    chamadasRec = 0; profMax = 0;
    printf("\nSoma total: %d", somaRec(v, 0, 11, 1));
    printf(" (Chamadas: %d, Profundidade Max: %d)\n", chamadasRec, profMax);

    // Busca
    printf("Digite valor para busca: ");
    scanf("%d", &chave);
    chamadasRec = 0; profMax = 0;
    int res = buscaRec(v, 12, chave, 0, 1);
    
    if (res != -1) printf("Encontrado no indice %d.", res);
    else printf("Valor nao encontrado.");
    printf(" (Chamadas: %d, Profundidade Max: %d)\n", chamadasRec, profMax);

    return 0;
}