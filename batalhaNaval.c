#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);  // cabeçalho da coluna
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);  // índice da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se o navio pode ser posicionado horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        if (tabuleiro[linha][coluna + j] != VALOR_AGUA)
            return 0;  // sobreposição
    }
    return 1;
}

// Função para verificar se o navio pode ser posicionado verticalmente
int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        return 0;

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != VALOR_AGUA)
            return 0;  // sobreposição
    }
    return 1;
}

// Posiciona um navio horizontal no tabuleiro
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][coluna + j] = VALOR_NAVIO;
    }
}

// Posiciona um navio vertical no tabuleiro
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = VALOR_NAVIO;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializar o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas fixas para os navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 7;

    // Validar e posicionar navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal);
    } else {
        printf("Erro: Não é possível posicionar o navio horizontal nessa posição.\n");
        return 1;
    }

    // Validar e posicionar navio vertical
    if (podePosicionarVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical);
    } else {
        printf("Erro: Não é possível posicionar o navio vertical nessa posição.\n");
        return 1;
    }

    // Exibir o tabuleiro final com os navios posicionados
    printf("\n Tabuleiro com os navios posicionados:\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

