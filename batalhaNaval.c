#include <stdio.h>

int main() {
    //tabuleiro
    int tabuleiro[10][10];

    // tabuleiro com ZEROS
    for(int linha = 0; linha < 10; linha++) {
        for(int coluna = 0; coluna < 10; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    // Posicionar os navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Navio VERTICAL na coluna B, linhas 7-8-9 (índices 6 a 8,1)
    int linha_vertical = 6;
    int coluna_vertical = 1;
    for(int i = 0; i < 3; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Letras no topo (A até J)
    char letras[] = {'A','B','C','D','E','F','G','H','I','J'};

    printf("   "); // Espaço antes das letras
    for(int i = 0; i < 10; i++) {
        printf(" %c ", letras[i]);
    }
    printf("\n");

    // Mostrar linhas numeradas com o conteúdo do tabuleiro
    for(int linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1); // número da linha (começa do 1)
        for(int coluna = 0; coluna < 10; coluna++) {
            printf(" %d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
