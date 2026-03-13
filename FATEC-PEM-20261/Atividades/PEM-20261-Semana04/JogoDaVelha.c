/*João Pedro de Queiroz Leite
12/03/2026
Fatec Ipiranga ADS Vespertino
Objetivo da atividade é realizar um jogo da velha*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// variaveis globais
char tab[3][3];
int i, j; 
char vazio = ' ';

/*optei por fazer funções externas do Main, pois durante minhas pesquisas cheguei a conclusão que isso deixaria o código mais
organizado e facil de ler, alem de facilitar a manutenção futura, caso seja necessario adicionar ou modificar alguma 
funcionalidade.*/

// Limpa as casas da matriz
void zeraTabuleiro() {
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tab[i][j] = vazio;
        }
    }
}

// Desenha o tabuleiro na tela com as coordenadas de guia
void mostrarJogo() {
    printf("\n\n\t      1   2   3\n\n");
    
    for (i = 0; i < 3; i++) {
        printf("\t %d  ", i + 1); 
        for (j = 0; j < 3; j++) {
            printf(" %c ", tab[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("\t    ---+---+---\n"); 
        }
    }
    printf("\n");
}

// Ve se a linha ta completa
int checarLinha(int linhaIndex, char simbolo) {
    if (tab[linhaIndex][0] == simbolo && tab[linhaIndex][1] == simbolo && tab[linhaIndex][2] == simbolo) {
        return 1;
    }
    return 0;
}

// Acumula vitorias nas linhas
int totalLinhas(char s) {
    int pontos = 0;
    for (i = 0; i < 3; i++) {
        pontos += checarLinha(i, s);
    }
    return pontos;
}

// Ve se a coluna ta completa
int checarCol(int colIndex, char simbolo) {
    if (tab[0][colIndex] == simbolo && tab[1][colIndex] == simbolo && tab[2][colIndex] == simbolo) {
        return 1;
    }
    return 0;
}

// Acumula vitorias nas colunas
int totalColunas(char s) {
    int pontos = 0;
    for (j = 0; j < 3; j++) {
        pontos += checarCol(j, s);
    }
    return pontos;
}

// Checa a diagonal principal (de cima-esquerda para baixo-direita)
int ganhouDiagPrin(char s) {
    if (tab[0][0] == s && tab[1][1] == s && tab[2][2] == s) return 1;
    return 0;
}

// Checa a diagonal secundaria (de cima-direita para baixo-esquerda)
int ganhouDiagSec(char s) {
    if (tab[0][2] == s && tab[1][1] == s && tab[2][0] == s) return 1;
    return 0;
}

// Validador de posicao: ve se ta dentro do limite e se ta vazio
int posicaoVazia(int l, int co) {
    if (l >= 0 && l < 3 && co >= 0 && co < 3 && tab[l][co] == vazio) {
        return 1;
    }
    return 0;
}

/*Pega os dados do jogador e ja tira 1 para a matriz Pega os dados do jogador e aceita 1 1 ou 1,1*/
void pegarJogada(char player) {
    int linUser, colUser;
    char c; // Variável auxiliar para capturar a vírgula se ela existir

    printf("Vez do %c, escolha linha e coluna (ex: 1 1 ou 1,1): ", player);

    // Tenta ler o primeiro número. Se falhar, limpa o buffer.
    if (scanf("%d", &linUser) != 1) {
        while (getchar() != '\n');
        linUser = -1; 
    } else {
        // Após o primeiro número, verifica se o próximo caractere é uma vírgula
        // O espaço antes do %c ignora espaços em branco automáticos
        if (scanf(" %c", &c) == 1) {
            if (c != ',') {
                // Se não for vírgula, devolvemos o caractere para o buffer 
                // pois ele já pode ser o segundo número
                ungetc(c, stdin);
            }
        }
        // Agora lê o segundo número
        if (scanf("%d", &colUser) != 1) {
            while (getchar() != '\n');
            colUser = -1;
        }
    }

    // Validação de posição
    while (posicaoVazia(linUser - 1, colUser - 1) == 0) {
        printf("Entrada invalida ou lugar ocupado! Tenta outro (ex: 1 1 ou 1,1): ");
        // Repete a lógica de limpeza e nova tentativa
        while (getchar() != '\n'); 
        if (scanf("%d", &linUser) == 1) {
            if (scanf(" %c", &c) == 1 && c != ',') ungetc(c, stdin);
            scanf("%d", &colUser);
        } else {
            linUser = -1;
        }
    }
    tab[linUser - 1][colUser - 1] = player;
}

// Ve se o jogo ainda pode continuar
int casasLivres() {
    int n = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (tab[i][j] == vazio) n++;
        }
    }
    return n;
}

// Motor do jogo
void rodarPartida() {
    int turno = 1, winX = 0, winO = 0;
    char p1 = 'X', p2 = 'O';

    do {
        mostrarJogo();
        
        if (turno == 1) {
            pegarJogada(p1);
            winX += totalLinhas(p1);
            winX += totalColunas(p1);
            winX += ganhouDiagPrin(p1);
            winX += ganhouDiagSec(p1);
            
            if (winX == 0) turno = 2; // Passa pro Jogador 'O'
        } else {
            pegarJogada(p2);
            winO += totalLinhas(p2);
            winO += totalColunas(p2);
            winO += ganhouDiagPrin(p2);
            winO += ganhouDiagSec(p2);
            
            if (winO == 0) turno = 1; // Volta pro Jogador 'X'
        }
        
    } while (winX == 0 && winO == 0 && casasLivres() > 0);

    mostrarJogo();
    
    if (winX >= 1) {
        printf("\nO Jogador 1 (X) ganhou a partida!\n");
    } else if (winO >= 1) {
        printf("\nO Jogador 2 (O) ganhou a partida!\n");
    } else {
        printf("\nvixi, deu velha!\n");
    }
}

int main() {
    int repetir;
    do {
        zeraTabuleiro();
        rodarPartida();  
        printf("\nQuer jogar de novo? (1 para Sim): ");
        scanf("%d", &repetir);
    } while (repetir == 1);
    
    return 0;
}
