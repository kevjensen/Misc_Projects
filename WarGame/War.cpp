//
// Created by kev_j on 1/21/2020.
//

#include "War.h"

// Builds the game deck for war
void War::build_deck() {
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 2; face < 15; ++face) {
            deck.push_back(Card{Card::Face(face), Card::Suit(suit)});
        }
    }
}

int War::hands_played() {
    int count = 0;
    double sum = 0;
    for (int games_played = 0; games_played < 10; ++games_played) {
        while (!player1_deck.empty() && !player2_deck.empty()) {
            play_hand();
            ++count;
            sum += count;
        }
    }
    std::cout << "Total number of hands = " << sum << "\n";
    std::cout << "Average number of hands over 10 games = " << sum/10 << "\n";
    return count;
}

void War::shuffle_common_deck(std::list<Card> &common_deck) {
    std::vector<Card> v{common_deck.begin(), common_deck.end()};

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(), g);
    common_deck.clear();
    std::copy(v.begin(), v.end(), std::back_inserter(common_deck));
}

// Constructor to build, shuffle, and distribute decks
War::War() {
    build_deck();
    shuffle_common_deck(deck);
    divvy_deck();
}

void War::divvy_deck() {
    for (int i = 0; i < 26; ++i) {
        player1_deck.push_back(deck.back());
        deck.pop_back();
    }
    for (int j = 0; j < 26; ++j) {
        player2_deck.push_back(deck.back());
        deck.pop_back();
    }
}

void War::test_hands () {
    // Test 1 - Basic comparison of same card with same suit
    player1_deck.push_front(Card(Card::Face::K, Card::Suit::Spades));
    player2_deck.push_front(Card(Card::Face::A, Card::Suit::Spades));
    if (!(player1_deck.front() < player2_deck.front())) {
        std::cout << "Error: Expected player1_deck KSpades < player2_deck ASpades" << "\n";
    }
    else {
        std::cout << "player2_deck ASpades > player1_deck KSpades correct." << "\n";
    }
    // Test 2 - More complex comparison of cards with different Suits
    player1_deck.push_front(Card(Card::Face::Nine, Card::Suit::Hearts));
    player2_deck.push_front(Card(Card::Face::Ten, Card::Suit::Clubs));
    if (!(player1_deck.front() < player2_deck.front())) {
        std::cout << "Error: Expected player1_deck 9Hearts < player2_deck 10Clubs" << "\n";
    }
    else {
        std::cout << "player2_deck 10Clubs > player1_deck 9Hearts correct." << "\n";
    }
    // Test 3 - Pushing Cards to Back of deck to simulate winning hands
    player1_deck.push_front(Card(Card::Face::Q, Card::Suit::Hearts));
    player2_deck.push_front(Card(Card::Face::K, Card::Suit::Diamonds));
    // push_back two cards to simulate winning a previous hand
    player2_deck.push_back(Card(Card::Face::Ten, Card::Suit::Spades));
    player2_deck.push_back(Card(Card::Face::Q, Card::Suit::Clubs));

    if (!(player1_deck.front() < player2_deck.front())) {
        std::cout << "Error: Expected player1_deck QHearts < player2_deck KDiamonds" << "\n";
    }
    else {
        std::cout << "player2_deck KDiamonds > player1_deck QHearts correct." << "\n";
    }
    // Checking sizes of respective decks; player1_deck should equal 29; player2_deck should equal 31
    std::cout << player1_deck.size() << "\n";
    std::cout << player2_deck.size() << "\n";
    {
        player1_deck.clear();
        player2_deck.clear();

        player1_deck.push_back(Card(Card::Face::Q, Card::Suit::Spades));
        player2_deck.push_back((Card(Card::Face::Ten, Card::Suit::Hearts)));

        ;play_hand();

        if (player1_deck.size() != 2) {
            std::cout << "Error: Expected player1_deck to be size 2.";
        }
        if (player2_deck.size() != 0) {
            std::cout << "Error: Expected player2_deck to be size 0.";
        }
    }
}

 void War::play_hand() {
    int winner = 0;
    std::list<Card> common_pool;

    while (winner == 0) {
        // Ensure both players have cards to play
        if (player1_deck.empty() || player2_deck.empty()) {
            return;
        }

        // Determine who the winner is or if there is a tie
        if (player1_deck.front() > player2_deck.front()) {
            winner = 1;
        } else if (player1_deck.front() == player2_deck.front()) {
            winner = 0;
        } else {
            winner = 2;
        }
        common_pool.push_back(player1_deck.front());
        player1_deck.pop_front();
        common_pool.push_back(player2_deck.front());
        player2_deck.pop_front();
    }

    shuffle_common_deck(common_pool);

    // Places common pool at back of winner's deck
    if (winner == 1) {
        player1_deck.splice(player1_deck.end(), common_pool);
    }
    if (winner == 2) {
        player2_deck.splice(player2_deck.end(), common_pool);
    }
}

std::ostream &operator<<(std::ostream &os, const War &deck) {
    // Output game deck size and deck elements
    os << "Deck (" <<deck.deck.size() << "):\n";
    for (auto &i : deck.deck) {
        os << i;
    }
    // Output player 1 decks size and elements
    os << "Deck (" <<deck.player1_deck.size() << "):\n";
    for (auto &i : deck.player1_deck) {
        os << i;
    }
    // Output player 2 deck size and elements
    os << "Deck (" <<deck.player2_deck.size() << "):\n";
    for (auto &i : deck.player2_deck) {
        os << i;
    }
    return os;
}


