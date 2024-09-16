#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 9
#define COLS 9
#define MINES 10

void initializeBoard(char board[ROWS][COLS], char value) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = value;
        }
    }
}

void placeMines(char board[ROWS][COLS]) {
    int placedMines = 0;
    srand(time(0));

    while (placedMines < MINES) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (board[row][col] != '*') {
            board[row][col] = '*';
            placedMines++;
        }
    }
}

int isValid(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

int countAdjacentMines(char board[ROWS][COLS], int row, int col) {
    int mineCount = 0;
    int rowDirections[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int colDirections[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int i = 0; i < 8; i++) {
        int newRow = row + rowDirections[i];
        int newCol = col + colDirections[i];
        if (isValid(newRow, newCol) && board[newRow][newCol] == '*') {
            mineCount++;
        }
    }

    return mineCount;
}

void revealBoard(char board[ROWS][COLS], char displayBoard[ROWS][COLS], int row, int col) {
    if (!isValid(row, col) || displayBoard[row][col] != '-') {
        return;
    }

    int adjacentMines = countAdjacentMines(board, row, col);
    displayBoard[row][col] = adjacentMines + '0';

    if (adjacentMines == 0) {
        displayBoard[row][col] = ' ';
        int rowDirections[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int colDirections[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < 8; i++) {
            revealBoard(board, displayBoard, row + rowDirections[i], col + colDirections[i]);
        }
    }
}

void printBoard(char board[ROWS][COLS]) {
    printf("\n");
    printf("    ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    for (int i = 0; i < ROWS; i++) {
        printf("%d   ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[ROWS][COLS];
    char displayBoard[ROWS][COLS];
    int gameOver = 0;

    initializeBoard(board, '-');
    initializeBoard(displayBoard, '-');

    placeMines(board);

    while (!gameOver) {
        printBoard(displayBoard);

        int row, col;
        printf("Satır ve sütun giriniz (örnek: 1 2): ");
        scanf("%d %d", &row, &col);

        if (!isValid(row, col)) {
            printf("Geçersiz koordinatlar. Tekrar deneyin.\n");
            continue;
        }

        if (board[row][col] == '*') {
            printf("\n--- Mayına Bastınız! Oyun Bitti! ---\n");
            gameOver = 1;
            printBoard(board);
        } else {
            revealBoard(board, displayBoard, row, col);
            int unrevealedCount = 0;
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (displayBoard[i][j] == '-') {
                        unrevealedCount++;
                    }
                }
            }
            if (unrevealedCount == MINES) {
                printf("\n--- Tebrikler! Oyunu Kazandınız! ---\n");
                printBoard(board);
                gameOver = 1;
            }
        }
    }

    return 0;
}
