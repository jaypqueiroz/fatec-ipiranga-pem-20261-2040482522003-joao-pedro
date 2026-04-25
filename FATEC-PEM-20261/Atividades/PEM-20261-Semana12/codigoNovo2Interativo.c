/*----------------------------------------------------------*
* Aluno: João Pedro                                         * 
* RA: 2040482522003                                         *
* Objetivo: Paradigma Iterativo                             *
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
int batidas_while = 0; 

void processarHierarquiaIterativo(int index_raiz, int limite_profundidade) {
    int pilha_ids[MAX_PASTAS];
    int pilha_niveis[MAX_PASTAS];
    int topo = -1;

    topo++;
    pilha_ids[topo] = index_raiz;
    pilha_niveis[topo] = 0;

    printf("\n--- RELATORIO DE HIERARQUIA---\n");

    while (topo >= 0) {
        batidas_while++;

        int atual = pilha_ids[topo];
        int nivel = pilha_niveis[topo];
        topo--;

        if (nivel > limite_profundidade) continue;

        for (int i = 0; i < nivel; i++) printf("  ");
        printf("|-- %s [%.2f GB]", drive[atual].nome, drive[atual].tamanho_proprio);
        
        if (drive[atual].tamanho_proprio > LIMITE_ALERTA) {
            printf(" [!] ALERTA: GARGALO DETECTADO");
        }
        printf("\n");

        for (int i = drive[atual].qtd_sub - 1; i >= 0; i--) {
            if (topo < MAX_PASTAS - 1) {
                topo++;
                pilha_ids[topo] = drive[atual].subpastas_indices[i];
                pilha_niveis[topo] = nivel + 1;
            }
        }
    }
}

int main() {

    strcpy(drive[0].nome, "RAIZ"); drive[0].tamanho_proprio = 10.0; drive[0].qtd_sub = 2;
    drive[0].subpastas_indices[0] = 1; drive[0].subpastas_indices[1] = 2;
    strcpy(drive[1].nome, "Projetos_TI"); drive[1].tamanho_proprio = 50.0; drive[1].qtd_sub = 1;
    drive[1].subpastas_indices[0] = 3;
    strcpy(drive[2].nome, "Backups_Antigos"); drive[2].tamanho_proprio = 350.0; drive[2].qtd_sub = 0;
    strcpy(drive[3].nome, "Videos_Aulas"); drive[3].tamanho_proprio = 280.0; drive[3].qtd_sub = 0;

    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    clock_t start = clock(); 

    processarHierarquiaIterativo(0, limite);
    
    clock_t t_ticks = clock() - start; 
    double tempo_seg = ((double)t_ticks) / CLOCKS_PER_SEC;

    printf("-------------------------------------------\n");
    printf("ESTATISTICAS DE DESEMPENHO:\n");
    printf("- Batidas no Laço: %d\n", batidas_while);
    printf("- Ciclos de Clock (CPU): %ld\n", (long)t_ticks);
    printf("- Tempo Real de Execucao: %.6f seg\n", tempo_seg);
    printf("-------------------------------------------\n");

    return 0;
}