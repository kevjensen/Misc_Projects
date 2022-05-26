#include <iostream>
#include "Move.h"
#include "Board.h"

Move read_move(Board b);

int main() {

    // Build board for game. Initialize player. Initialize Game state.
    Board b;
    CurrentPlayer current_player = CurrentPlayer::X;
    GameState game_state = GameState::not_over;
    // Game Loop
    while (game_state == GameState::not_over) {
        // Print board out.
        b.print();
        std::cout << "Player ";
        switch(b.getCurrentPlayer(current_player)) {
            case CurrentPlayer::X:
                std::cout << "X";
                break;
            case CurrentPlayer::O:
                std::cout << "O";
                break;
        }
        std::cout << "'s turn\n";
        Move m = read_move(b);
        b.apply_move(m, current_player);
        b.status(game_state, b);
        // Switches current player
        if (current_player == CurrentPlayer::O) {
            current_player = CurrentPlayer::X;
        }
        else {
            current_player = CurrentPlayer::O;
            }

    }
}

Move read_move(Board b) {

    for (;;) {
        Move m{};
        std::cin >> m.row;
        std::cin >> m.col;

        -- m.row;
        -- m.col;

        if (b.is_valid(m)) {
            return m;
        }
    }
}