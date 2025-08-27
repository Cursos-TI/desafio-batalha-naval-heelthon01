#include <stdio.h>
#include <stdbool.h>

#define TAM 10   // tamanho do tabuleiro
#define NAVIO 3  // tamanho do navio

// Função para inicializar o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar o navio
bool podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        // Verifica se cabe na horizontal
        if (coluna + NAVIO > TAM) return false;
        for (int j = 0; j < NAVIO; j++) {
            if (tabuleiro[linha][coluna + j] != 0) return false; // já ocupado
        }
    } else if (orientacao == 'V') {
        // Verifica se cabe na vertical
        if (linha + NAVIO > TAM) return false;
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return false; // já ocupado
        }
    }
    return true;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int j = 0; j < NAVIO; j++) {
            tabuleiro[linha][coluna + j] = 3;
        }
    } else if (orientacao == 'V') {
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas definidas no código (linha, coluna)
    int linha1 = 2, coluna1 = 4; // navio horizontal
    int linha2 = 5, coluna2 = 7; // navio vertical

    // Tenta posicionar o primeiro navio (horizontal)
    if (podePosicionar(tabuleiro, linha1, coluna1, 'H')) {
        posicionarNavio(tabuleiro, linha1, coluna1, 'H');
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Tenta posicionar o segundo navio (vertical)
    if (podePosicionar(tabuleiro, linha2, coluna2, 'V')) {
        posicionarNavio(tabuleiro, linha2, coluna2, 'V');
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Exibir tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
