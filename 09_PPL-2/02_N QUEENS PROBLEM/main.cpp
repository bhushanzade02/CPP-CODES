// main.cpp
#include "Board.h"

int main() {
    Board board;
    if (board.solve()) {
        board.printBoard();
    } else {
        std::cout << "No solution exists" << std::endl;
    }
    return 0;
}
