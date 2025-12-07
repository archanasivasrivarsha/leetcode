#include <stdbool.h>
#include <stdlib.h>

bool isSafe(char** board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) return false; // check row
        if (board[i][col] == num) return false; // check column
        // check 3x3 sub-box
        int r = 3 * (row / 3) + i / 3;
        int c = 3 * (col / 3) + i % 3;
        if (board[r][c] == num) return false;
    }
    return true;
}

bool solveSudokuHelper(char** board, int boardSize, int* boardColSize) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudokuHelper(board, boardSize, boardColSize))
                            return true;
                        board[row][col] = '.'; // backtrack
                    }
                }
                return false; // no valid number found
            }
        }
    }
    return true; // solved
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solveSudokuHelper(board, boardSize, boardColSize);
}
