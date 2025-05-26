#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_l, int origem_c) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int lin_tab = origem_l - TAM_HAB / 2 + i;
            int col_tab = origem_c - TAM_HAB / 2 + j;

            if (lin_tab >= 0 && lin_tab < TAM && col_tab >= 0 && col_tab < TAM) {
                if (habilidade[i][j] == 1 && tabuleiro[lin_tab][col_tab] != 3) {
                    tabuleiro[lin_tab][col_tab] = 5;
                }
            }
        }
    }
}

void gerarCruz(int cruz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == TAM_HAB / 2 || j == TAM_HAB / 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

void gerarCone(int cone[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (j >= (TAM_HAB / 2 - i) && j <= (TAM_HAB / 2 + i)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

void gerarOctaedro(int octaedro[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2) <= TAM_HAB / 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};
    printf("    ");
    for (int i = 0; i < TAM; i++) {
        printf(" %c ", letras[i]);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d  ", i + 1);
        for (int j = 0; j < TAM; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0};

    // NAVIOS
    int linha_h = 2, coluna_h = 4;
    for (int i = 0; i < 3 && coluna_h + i < TAM; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }

    int linha_v = 6, coluna_v = 1;
    for (int i = 0; i < 3 && linha_v + i < TAM; i++) {
        if (tabuleiro[linha_v + i][coluna_v] == 0) tabuleiro[linha_v + i][coluna_v] = 3;
    }

    int linha_d1 = 0, coluna_d1 = 0;
    for (int i = 0; i < 3 && linha_d1 + i < TAM && coluna_d1 + i < TAM; i++) {
        if (tabuleiro[linha_d1 + i][coluna_d1 + i] == 0) tabuleiro[linha_d1 + i][coluna_d1 + i] = 3;
    }

    int linha_d2 = 4, coluna_d2 = 6;
    for (int i = 0; i < 3 && linha_d2 + i < TAM && coluna_d2 - i >= 0; i++) {
        if (tabuleiro[linha_d2 + i][coluna_d2 - i] == 0) tabuleiro[linha_d2 + i][coluna_d2 - i] = 3;
    }

  
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);


    aplicarHabilidade(tabuleiro, cone, 5, 5);      
    aplicarHabilidade(tabuleiro, cruz, 8, 8);      
    aplicarHabilidade(tabuleiro, octaedro, 3, 2);  


    exibirTabuleiro(tabuleiro);

    return 0;
}
