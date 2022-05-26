//
// Created by kev_j on 1/21/2020.
//

#ifndef WARGAME_WAR_H
#define WARGAME_WAR_H

#include "Card.h"

class War {
public:
    // Constructor: sets up the deck, shuffles deck, and deals
    War ();

    // Member function that builds a card deck
    void build_deck();

    // Member variables
    std::list<Card> deck;
    std::list<Card> player1_deck;
    std::list<Card> player2_deck;

    // Member function that shuffles the decks
    void shuffle_common_deck (std::list<Card> &common_deck);

    // Member function that divvies the decks between players
    void divvy_deck();

    // Member function to play a game
    void play_hand();

    // How many hands are played in a game
    int hands_played();

    // Test hands against one another
    void test_hands();

    friend std::ostream &operator<<(std::ostream &os, const War &deck);
};

#endif //WARGAME_WAR_H
