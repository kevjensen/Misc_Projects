//
// Created by kev_j on 1/12/2020.
//

#include<iostream>
#include <vector>

#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

#include "Move.h"

enum class GameState {
    Xwins, Owins, tie, not_over
};

enum class CellState {
    X, O, empty
};

enum class CurrentPlayer {
    X, O
};

class Board {
public:
    Board();
    void build_board(int row, int col);
    void print();
    void apply_move(Move &move, CurrentPlayer current_player);
    CurrentPlayer getCurrentPlayer(CurrentPlayer current_player);
    bool is_valid(Move &move) const;
    void status(GameState &game_state, Board &b);


private:

    std::vector<std::vector<CellState>> board;


};





#endif //{}{}TI{}CTACTOE_TICT{}{}{}ACTOE_H
