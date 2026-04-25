/*----------------------------------------------------------*
* Aluno: João Pedro                                         *
* RA: 2040482522003                                         *
* Objetivo: Refatoração com Ponteiros                       *
*-----------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 50
#define LIMITE_ALERTA 300.0

typedef struct {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    int subpastas_indices[10];
    int qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];
int chamadas_funcao = 0;

float processarHierarquia(int idx, int nivel, int max_depth) {
    chamadas_funcao++;

    if (idx == -1 || nivel > max_depth) {
        return 0;
    }

    Pasta *p = &drive[idx];
    (*p).tamanho_total = (*p).tamanho_proprio;

    for (int i = 0; i < (*p).qtd_sub; i++) {
        int proximo = (*p).subpastas_indices[i];
        (*p).tamanho_total += processarHierarquia(proximo, nivel + 1, max_depth);
    }

    for (int j = 0; j < nivel; j++) printf("  ");
    printf("|-- %s [%.2f GB]", (*p).nome, (*p).tamanho_total);
    
    if ((*p).tamanho_total > LIMITE_ALERTA) {
        printf(" [!] ALERTA: GARGALO DETECTADO");
    }
    printf("\n");

    return (*p).tamanho_total;
}

int main() {

    strcpy(drive[0].nome, "RAIZ"); drive[0].tamanho_proprio = 10.0; drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1; drive[0].subpastas_indices[1] = 2;
    strcpy(drive[1].nome, "Projetos_TI"); drive[1].tamanho_proprio = 50.0; drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3;
    strcpy(drive[2].nome, "Backups_Antigos"); drive[2].tamanho_proprio = 350.0; drive[2].qtd_sub = 0;
    strcpy(drive[3].nome, "Videos_Aulas"); drive[3].tamanho_proprio = 280.0; drive[3].qtd_sub = 0;

    int limite;
    int *ptr_limite = &limite;
    printf("Defina o limite de profundidade: ");
    scanf("%d", ptr_limite);

    clock_t t_inicio = clock(); 

    printf("\n--- RELATORIO---\n");
    processarHierarquia(0, 0, *ptr_limite);
    
    clock_t t_ticks = clock() - t_inicio; 
    double tempo_seg = ((double)t_ticks) / CLOCKS_PER_SEC;

    printf("-------------------------------------------\n");
    printf("ESTATISTICAS DE DESEMPENHO:\n");
    printf("- Chamadas de Funcao: %d\n", chamadas_funcao);
    printf("- Ciclos de Clock (CPU): %ld\n", (long)t_ticks);
    printf("- Tempo Real de Execucao: %.6f seg\n", tempo_seg);
    printf("-------------------------------------------\n");

    return 0;
}