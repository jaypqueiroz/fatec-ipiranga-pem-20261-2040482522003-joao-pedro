/*João Pedro de Queiroz Leite
2040482522003

Disciplina: Programaçao Estruturada e Modular          
Prof. Veríssimo 
25/05/2026

O programa demonstra o uso de ponteiros para a
passagem de parâmetros por referência, permitindo 
que funções alterem diretamente o estado de variáveis 
e estruturas de dados definidas no escopo principal. 
Implementei funções para troca de valores, análise 
estatística de mínimos e máximos, e normalização de 
vetores de ponto flutuante, comprovando a eficácia dos
ponteiros no gerenciamento eficiente de memória e na 
comunicação entre diferentes partes do sistema.

*/

#include <stdio.h>

// 1. Troca valores de duas variáveis
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 2. Encontra min e max em um vetor
void minMax(int *v, int n, int *min, int *max) {
    *min = v[0];
    *max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];
    }
}

// 3. Normaliza vetor [0, 1]
void normalizaVetor(float *v, int n) {
    float max = v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] > max) max = v[i];
    }
    // Normalização: divide cada elemento pelo maior valor encontrado
    for (int i = 0; i < n; i++) {
        v[i] /= max;
    }
}

int main() {
    // Demonstração da função Troca
    int x = 10, y = 20;
    printf("Troca: Antes x=%d, y=%d", x, y);
    troca(&x, &y);
    printf(" | Depois x=%d, y=%d\n", x, y);

    // Demonstração da função MinMax
    int v[] = {5, 2, 9, 1, 7}, min, max;
    minMax(v, 5, &min, &max);
    printf("MinMax: Vetor [5,2,9,1,7] -> Min: %d, Max: %d\n", min, max);

    // Demonstração da função NormalizaVetor
    float fv[] = {10.0, 20.0, 50.0, 40.0};
    printf("Normalizacao: Antes [10, 20, 50, 40] -> Depois [");
    normalizaVetor(fv, 4);
    for(int i=0; i<4; i++) printf("%.2f%s", fv[i], i<3?", ":"");
    printf("]\n");

    return 0;
}