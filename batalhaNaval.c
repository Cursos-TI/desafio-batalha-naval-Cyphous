#include <stdio.h>

int main() {
    // 1. tabuleiro 10x10
    int tabuleiro[10][10];

    // 2. Preencher todas as posições com 0 
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // NAVIO 1 – Horizontal 
    int linha_h = 2, coluna_h = 4;
    if (coluna_h + 2 < 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linha_h][coluna_h + i] = 3;
        }
    }

    // NAVIO 2 – Vertical 
    int linha_v = 6, coluna_v = 1;
    if (linha_v + 2 < 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_v + i][coluna_v] == 0) {
                tabuleiro[linha_v + i][coluna_v] = 3;
            }
        }
    }

    // NAVIO 3 – Diagonal Principal
    int linha_d1 = 0, coluna_d1 = 0;
    if (linha_d1 + 2 < 10 && coluna_d1 + 2 < 10) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_d1 + i][coluna_d1 + i] == 0) {
                tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
            }
        }
    }

    // NAVIO 4 – Diagonal Secundária 
    int linha_d2 = 4, coluna_d2 = 6;
    if (linha_d2 + 2 < 10 && coluna_d2 - 2 >= 0) {
        for (int i = 0; i < 3; i++) {
            if (tabuleiro[linha_d2 + i][coluna_d2 - i] == 0) {
                tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
            }
        }
    }

    // Letras do topo (A até J)
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("    ");
    for (int i = 0; i < 10; i++) {
        printf(" %c ", letras[i]);
    }
    printf("\n");

    // Mostrar cada linha do tabuleiro
    for (int linha = 0; linha < 10; linha++) {
        printf("%2d  ", linha + 1); // Numeração da linha (1 a 10)
        for (int coluna = 0; coluna < 10; coluna++) {
            printf(" %d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
