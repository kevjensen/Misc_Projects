#include "notacto.h"

int main() {
    // Assign player variable
    int current_player = 1;
    // Create game board
    std::vector<std::vector<bool>> board = build_board(4, 4);
    // Game program loop
    while (!game_over(board)) {
        // Prompt player on appropriate turn
        for (;;) {
            // Prompt player
            std::cout << "Player " << current_player << "'s turn.\n";
            // Print game board
            print_board(board);
            int row, col;
            // Read, validate, and apply valid moves
            read_move(row, col);
            if (is_valid_move(board, row, col)) {
                apply_move(board, row, col);
                break;
            } else {
                std::cout << "Place is already taken. Try again.\n";
            }
        }
        // Switch player for next round
        if (current_player == 1) {
            current_player = 2;
        } else {
            current_player = 1;
        }
    }
    // Declare winner
    std::cout << "Game over. Player " << current_player << " wins!";
    return 0;
}