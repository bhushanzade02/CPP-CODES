// Board.cpp
#include "Board.h"

Board::Board() : board(8, std::vector<char>(8, '-')) {}

bool Board::isSafe(int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 'Q') return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

bool Board::solve(int col) {
    if (col >= 8) return true;
    for (int i = 0; i < 8; i++) {
        if (isSafe(i, col)) {
            board[i][col] = 'Q';
            if (solve(col + 1)) return true;
            board[i][col] = '-';
        }
    }
    return false;
}

void Board::printBoard() {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}
