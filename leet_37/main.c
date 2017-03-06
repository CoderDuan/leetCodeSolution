#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int charToInt(char c) {
    return (int)(c - '0');
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    char*** sln = (char***)malloc(boardRowSize*sizeof(char**));
    int i, j, k;
    for (i = 0; i < boardRowSize; i++) {
        sln[i] = (char**)malloc(boardRowSize*sizeof(char*));
        for (j = 0; j < boardColSize; j++) {
            sln[i][j] = (char*)malloc(9*sizeof(char));
            if (board[i][j] == '.') {
                for (k = 0; k < 9; k++)
                    sln[i][j][k] = k + 1;
            } else
                memset(sln[i][j], '-', 9);
        }
    }
    
    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            if (board[i][j] == '.') {
                int localRow = i/3*3;
                int localCol = j/3*3;
                int ii, jj;
                for (ii = localRow; ii < localRow + 3; ii++) {
                    for (jj = localCol; jj < localCol + 3; jj++) {
                        if (board[i][j] != '.') {
                            int num = charToInt(board[i][j]);
                            
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < boardRowSize; i++) {
        for (j = 0; j < boardColSize; j++) {
            free(sln[i][j]);
        }
        free(sln[i]);
    }
}

int main() {
    return 0;
}