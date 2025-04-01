# Chessboard Project

This is a C++ project that simulates a chessboard and handles queen movements and constraints. The project consists of several files to manage the chessboard, queens, and the main program logic.

## Project Structure

- **Board.hpp / Board.cpp**: These files represent the chessboard and provide methods for operations on the chessboard.
- **Queen.hpp / Queen.cpp**: These files handle the logic for queen movements, including the constraints based on chess rules.
- **main.cpp**: This file is responsible for the overall program logic, input, and output.
- **Makefile**: Used for compiling and building the project.

## Compilation Instructions

1. Compile the project using the Makefile:
    ```bash
    make
    ```

2. Run the compiled program:
    ```bash
    ./chessboard
    ```

## Features

- Chessboard representation using a 2D array.
- Queen movement logic ensuring no two queens can threaten each other.
- Simple input/output for user interaction.
