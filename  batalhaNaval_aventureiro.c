#include <stdio.h>
#include <stdbool.h>

#define TAM 10   // tamanho fixo do tabuleiro
#define NAVIO 3  // tamanho fixo dos navios (3 posições)

// =======================================================================
// Inicializa o tabuleiro preenchendo todas as posições com 0 (água).
// =======================================================================
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// =======================================================================
// Imprime o tabuleiro no console, mostrando 0 (água) e 3 (navio).
// =======================================================================
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// =======================================================================
// Função para verificar se o navio pode ser colocado sem ultrapassar os
// limites do tabuleiro e sem se sobrepor a outro navio já colocado.
// orientacao:
//   'H' -> horizontal
//   'V' -> vertical
//   'D' -> diagonal principal (\) 
//   'A' -> diagonal anti-principal (/)
// =======================================================================
bool podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        if (coluna + NAVIO > TAM) return false;
        for (int j = 0; j < NAVIO; j++)
            if (tabuleiro[linha][coluna + j] != 0) return false;
    }
    else if (orientacao == 'V') {
        if (linha + NAVIO > TAM) return false;
        for (int i = 0; i < NAVIO; i++)
            if (tabuleiro[linha + i][coluna] != 0) return false;
    }
    else if (orientacao == 'D') { // diagonal principal (\)
        if (linha + NAVIO > TAM || coluna + NAVIO > TAM) return false;
        for (int k = 0; k < NAVIO; k++)
            if (tabuleiro[linha + k][coluna + k] != 0) return false;
    }
    else if (orientacao == 'A') { // diagonal anti-principal (/)
        if (linha + NAVIO > TAM || coluna - (NAVIO - 1) < 0) return false;
        for (int k = 0; k < NAVIO; k++)
            if (tabuleiro[linha + k][coluna - k] != 0) return false;
    }
    return true;
}

// =======================================================================
// Posiciona o navio no tabuleiro, assumindo que já foi validado antes.
// =======================================================================
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, char orientacao) {
    if (orientacao == 'H') {
        for (int j = 0; j < NAVIO; j++)
            tabuleiro[linha][coluna + j] = 3;
    }
    else if (orientacao == 'V') {
        for (int i = 0; i < NAVIO; i++)
            tabuleiro[linha + i][coluna] = 3;
    }
    else if (orientacao == 'D') { // diagonal principal
        for (int k = 0; k < NAVIO; k++)
            tabuleiro[linha + k][coluna + k] = 3;
    }
    else if (orientacao == 'A') { // diagonal anti-principal
        for (int k = 0; k < NAVIO; k++)
            tabuleiro[linha + k][coluna - k] = 3;
    }
}

// =======================================================================
// Programa principal
// =======================================================================
int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Definição das coordenadas iniciais dos 4 navios
    // (linha, coluna, orientação)
    int linha1 = 2, coluna1 = 1; char o1 = 'H'; // horizontal
    int linha2 = 5, coluna2 = 7; char o2 = 'V'; // vertical
    int linha3 = 0, coluna3 = 0; char o3 = 'D'; // diagonal principal
    int linha4 = 4, coluna4 = 9; char o4 = 'A'; // diagonal anti-principal

    // Tenta posicionar cada navio
    if (podePosicionar(tabuleiro, linha1, coluna1, o1)) posicionarNavio(tabuleiro, linha1, coluna1, o1);
    else printf("Falha ao posicionar navio 1.\n");

    if (podePosicionar(tabuleiro, linha2, coluna2, o2)) posicionarNavio(tabuleiro, linha2, coluna2, o2);
    else printf("Falha ao posicionar navio 2.\n");

    if (podePosicionar(tabuleiro, linha3, coluna3, o3)) posicionarNavio(tabuleiro, linha3, coluna3, o3);
    else printf("Falha ao posicionar navio 3.\n");

    if (podePosicionar(tabuleiro, linha4, coluna4, o4)) posicionarNavio(tabuleiro, linha4, coluna4, o4);
    else printf("Falha ao posicionar navio 4.\n");

    // Mostra tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
