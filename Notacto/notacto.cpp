#include "notacto.h"

#include <iostream>

std::vector<std::vector<bool>> build_board(int rows, int col) {
    std::vector<std::vector<bool>> board;
    for (int i = 0; i < rows; ++i) {
        std::vector<bool> row;
        for (int j = 0; j < col; ++j) {
            row.push_back(false);
        }
        board.push_back(row);
    }
    return board;
}

void read_move(int &row, int &col) {
    for (;;) {
        // Player inputs spot on board
        std::cout << "Enter a row and a column: ";
        std::cin >> row >> col;

        // Ensure move is within the range
        if ((row && col) < 1 || (row && col > 4)) {
            std::cout << "Error: Invalid range.\n";
        } else {
            --row;
            --col;
            break;
        }
    }
}

void print_board(const std::vector<std::vector<bool>> &board) {
    // Using indices to create the game board
    for (int row = 0; row < board.size(); ++row) {
        for (int col = 0; col < board.size(); ++col) {
            std::cout << board[row][col] << " ";
        }
        std::cout << "\n";
    }
}

bool is_valid_move(std::vector<std::vector<bool>> &board, int row, int col) {
    if (board[row][col] == false) {
        return true;
    }
    return false;
}

void apply_move(std::vector<std::vector<bool>> &board, int row, int col) {
    if (board[row][col] == false) {
        board[row][col] = true;
    }
}

bool game_over(std::vector<std::vector<bool>> &board) {
    for (int row = 0; row < 4; ++row) {
        bool complete = true;
        for (int col = 0; col < 4; ++col)
            if (!board[row][col]) {
                complete = false;
                break;
            }
        if (complete) {
            return true;
        }
    }
    for (int col = 0; col < 4; ++col) {
        bool complete = true;
        for (int row = 0; row < 4; ++row) {
            if (!board[row][col]) {
                complete = false;
                break;
            }
        }
        if (complete) {
            return true;
        }
    }
    if (board[0][0] == true && board[1][1] == true && board[2][2] == true && board[3][3] == true) {
        return true;
    }
    if (board[3][0] == true && board[2][1] == true && board[1][2] == true && board[0][3] == true) {
        return true;
    } else {
        return false;
    }
}