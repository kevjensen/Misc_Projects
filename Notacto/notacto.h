#ifndef INC_NOTACTOE_NOTACTO_H
#define INC_NOTACTOE_NOTACTO_H

// include guard

#include <iostream>
#include <vector>

void read_move(int &row, int &col);
std::vector <std::vector <bool>> build_board(int rows, int col);

// Not making a copy, and not expecting the parameter to change
void print_board(const std::vector<std::vector<bool>> &board);
bool is_valid_move(std::vector<std::vector<bool>> &board, int row, int col);
bool game_over (std::vector<std::vector<bool>> &board);
void apply_move(std::vector<std::vector<bool>> &board, int row, int col);
#endif //NOTACTOE_NOTACTO_H
