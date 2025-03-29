// Board.h
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

class Board {
private:
    std::vector<std::vector<char>> board;
    bool isSafe(int row, int col);
public:
    Board();
    bool solve(int col = 0);
    void printBoard();
};

#endif
