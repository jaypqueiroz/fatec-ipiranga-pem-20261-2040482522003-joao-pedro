/* João Pedro de Queiroz Leite
   19-03-2026
   ADS - Vespertino
   Programação Estruturada e Modular 
   Atividade Semana 5: Xeque Pastor
   Este código tem por objetivo simular a jogada do xadrez conhecido por xeque-pastor*/

#include <stdio.h>
#include <string.h>

// Definindo o tamanho do tabuleiro como 8
#define TAM 8

// --- FUNÇÃO 1: MOSTRAR O TABULEIRO ---
// Essa função imprime a matriz na tela com as bordas de 1 a 8 e a a h
void desenha(char tab[TAM][TAM][4], char *titulo) {
    int i, j;
    printf("\n---------- %s ----------\n", titulo);
    
    for (i = 0; i < TAM; i++) {
        // Imprime o número da linha (de 8 até 1)
        printf("%d ", 8 - i); 
        for (j = 0; j < TAM; j++) {
            printf("%-4s", tab[i][j]);
        }
        printf("\n");
    }
    // Imprime as letras das colunas embaixo
    printf("   a   b   c   d   e   f   g   h\n");
    printf("------------------------------------------\n");
}

// --- FUNÇÃO 2: MOVER AS PEÇAS ---
// Pega a peça da posição antiga, coloca no destino e deixa "..." pra trás
void mexe(char tab[TAM][TAM][4], int l_ant, int c_ant, int l_nova, int c_nova) {
    char p_salva[4];
    
    // Copia a sigla da peça
    strcpy(p_salva, tab[l_ant][c_ant]);
    // Limpa onde ela estava
    strcpy(tab[l_ant][c_ant], "...");
    // Coloca na casa nova
    strcpy(tab[l_nova][c_nova], p_salva);
}

// --- FUNÇÃO 3: MONTAR O JOGO ---
// Coloca as peças nas posições certas do começo do jogo
void inicia(char tab[TAM][TAM][4]) {
    char pecas[TAM][TAM][4] = {
        {"tP1", "cP2", "bP3", "dP4", "rP5", "bP6", "cP7", "tP8"},
        {"pP1", "pP2", "pP3", "pP4", "pP5", "pP6", "pP7", "pP8"},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "},
        {"pB1", "pB2", "pB3", "pB4", "pB5", "pB6", "pB7", "pB8"},
        {"tB1", "cB2", "bB3", "dB4", "rB5", "bB6", "cB7", "tB8"}
    };

    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            strcpy(tab[i][j], pecas[i][j]);
        }
    }
}

// --- PROGRAMA PRINCIPAL POR ÚLTIMO ---
int main() {
    // Matriz de 8x8, cada casa guarda 4 caracteres (3 da sigla + \0)
    char tabuleiro[TAM][TAM][4];

    // Início do jogo
    inicia(tabuleiro);
    desenha(tabuleiro, "POSICAO INICIAL");

    // 1º LANCE
    mexe(tabuleiro, 6, 4, 4, 4); // Branco e4
    desenha(tabuleiro, "Brancas jogam e4");
    
    mexe(tabuleiro, 1, 4, 3, 4); // Preto e5
    desenha(tabuleiro, "Pretas jogam e5");

    // 2º LANCE
    mexe(tabuleiro, 7, 5, 4, 2); // Branco Bc4
    desenha(tabuleiro, "Brancas jogam Bc4");
    
    mexe(tabuleiro, 0, 1, 2, 2); // Preto Cc6
    desenha(tabuleiro, "Pretas jogam Cc6");

    // 3º LANCE
    mexe(tabuleiro, 7, 3, 3, 7); // Branco Dh5
    desenha(tabuleiro, "Brancas jogam Dh5");
    
    mexe(tabuleiro, 0, 6, 2, 5); // Preto Cf6
    desenha(tabuleiro, "Pretas jogam Cf6");

    // 4º LANCE: XEQUE-MATE
    mexe(tabuleiro, 3, 7, 1, 5); // Dama captura peão em f7
    desenha(tabuleiro, "Dxf7# - XEQUE MATE!");

    return 0;
}