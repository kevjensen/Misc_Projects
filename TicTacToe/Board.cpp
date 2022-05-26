//
// Created by kev_j on 1/12/2020.
//
#include <iostream>
#include "Board.h"
#include "Move.h"

void Board::build_board(int row, int col) {
    for (int i = 0; i < row; ++i) {
        std::vector<CellState> row;
        for (int j = 0; j < col; ++j) {
            row.push_back(CellState::empty);
        }
        board.push_back(row);
    }
}

void Board::print() {
// Using indices to create the game board
    for (int row = 0; row < board.size(); ++row) {
        for (int col = 0; col < board.size(); ++col) {
            switch (board[row][col]) {
                // Use enum class to construct board
                case CellState::empty:
                    std::cout << "-";
                    break;
                case CellState::X:
                    std::cout << "X";
                    break;
                case CellState::O:
                    std::cout << "O";
                    break;
            }
        }
        std::cout << "\n";
    }
}

// Constructor that builds game board
Board::Board() {
    build_board(3, 3);
}

CurrentPlayer Board::getCurrentPlayer(CurrentPlayer current_player) {
    // Gets current player
    return current_player;
}


bool Board::is_valid(Move &move) const {
    if ((move.row) < 0 || (move.col > 2)) {
        std::cout << "Error: Invalid range.\n";
        return false;
    }
    if (board[move.row][move.col] == CellState::empty) {
        return true;
    } else {
        std::cout << "Space already occupied. Choose another place.\n";
        return false;
    }
}

void Board::apply_move(Move &move, CurrentPlayer current_player) {
    if (current_player == CurrentPlayer::X) {
        board[move.row][move.col] = CellState::X;
    }
    if (current_player == CurrentPlayer::O) {
        board[move.row][move.col] = CellState::O;
    }
}


// Various patterns that complete the game.
void Board::status(GameState &game_state, Board &b) {

    if (board[0][0] == CellState::O && board[1][1] == CellState::O && board[2][2] == CellState::O) {
        std::cout << "Player O wins.\n";
        b.print();
        game_state = GameState::Owins;
    } else if (board[2][0] == CellState::O && board[1][1] == CellState::O && board[0][2] == CellState::O) {
        std::cout << "Player X wins.\n";
        b.print();
        game_state = GameState::Xwins;
    } else if (board[0][0] == CellState::X && board[1][1] == CellState::X && board[2][2] == CellState::X) {
        std::cout << "Player X wins.\n";
        b.print();
        game_state = GameState::Xwins;
    } else if (board[2][0] == CellState::X && board[1][1] == CellState::X && board[0][2] == CellState::X) {
        std::cout << "Player X wins.\n";
        b.print();
        game_state = GameState::Xwins;
    } else if (board[0][0] == CellState::X && board[0][1] == CellState::X && board[0][2] == CellState::X) {
        std::cout << "Player X wins.\n";
        b.print();
        game_state = GameState::Xwins;
    } else if (board[0][0] == CellState::O && board[0][1] == CellState::O && board[0][2] == CellState::O) {
        std::cout << "Player O wins.\n";
        b.print();
        game_state = GameState::Owins;
    } else if (board[1][0] == CellState::O && board[1][1] == CellState::O && board[1][2] == CellState::O) {
        std::cout << "Player O wins.\n";
        b.print();
        game_state = GameState::Owins;
    } else if (board[2][0] == CellState::O && board[2][1] == CellState::O && board[2][2] == CellState::O) {
        std::cout << "Player O wins.\n";
        b.print();
        game_state = GameState::Owins;
    } else if (board[2][0] == CellState::X && board[2][1] == CellState::X && board[2][2] == CellState::X) {
        std::cout << "Player X wins.\n";
        b.print();
        game_state = GameState::Xwins;
    } else if (board[1][0] == CellState::X && board[1][1] == CellState::X && board[1][2] == CellState::X) {
        std::cout << "Player X wins.\n";
        b.print();
        game_state = GameState::Xwins;
    } else if (board[0][0] != CellState::empty && board[0][1] != CellState::empty && board[0][2] != CellState::empty &&
            board[1][0] != CellState::empty && board[1][1] != CellState::empty && board[1][2] != CellState::empty &&
            board[2][0] != CellState::empty && board[2][1] != CellState::empty && board[2][2] != CellState::empty){
        std::cout << "Tie game.\n";
        b.print();
        game_state = GameState::tie;
    }
    else {
        game_state = GameState::not_over;
    }
}


