//
// Created by kev_j on 1/21/2020.
//

#include "Card.h"


Card::Card(Face face, Suit suit) {
    // Disambiguation
    this->face = face;
    this->suit = suit;
}

void Card::card_test() {
    Card A{Card::Face::A, Card::Suit::Hearts};
    Card B{Card::Face::K, Card::Suit::Hearts};
    if (!(B < A)) {
        std::cout<< "Error: Expected KH < AH\n";
    }
    else {
        std::cout<< "KH < AH correct";
    }

    Card C{Card::Face::J, Card::Suit::Clubs};
    Card D{Card::Face::Ten, Card::Suit::Spades};
    if (!(D < C)) {
        std::cout<< "Error: Expected TenSpades < JClubs\n";
    }
    else {
        std::cout<< "TenSpades < JClubs correct";
    }

    Card E{Card::Face::Three, Card::Suit::Diamonds};
    Card F{Card::Face::Two, Card::Suit::Hearts};
    if (!(F < E)) {
        std::cout<< "Error: Expected TwoHearts < ThreeDiamonds\n";
    }
    else {
        std::cout<< "TwoHearts < ThreeDiamonds correct";
    }

    Card G{Card::Face::Eight, Card::Suit::Spades};
    Card H{Card::Face::Four, Card::Suit::Diamonds};
    if (!(H < G)) {
        std::cout<< "Error: Expected FourDiamonds < EightSpades\n";
    }
    else {
        std::cout<< "FourDiamonds < EightSpades correct";
    }
}

// Allows cards to be compared using < operator
bool operator<(const Card &lhs, const Card &rhs) {
    return lhs.face < rhs.face;
}

// Allows cards to be compared using > operator
bool operator>(const Card &lhs, const Card &rhs) {
    return lhs.face > rhs.face;
}

// Allows cards to be compared using == operator
bool operator==(const Card &lhs, const Card &rhs) {
    return lhs.face == rhs.face;
}

// Overloads << operator to print Card suit and face
std::ostream &operator<<(std::ostream &os, const Card &card) {
    switch (card.face) {
        case Card::Face::Two: {
            std::cout << "2";
            break;
        }
        case Card::Face::Three: {
            std::cout << "3";
            break;
        }
        case Card::Face::Four: {
            std::cout << "4";
            break;
        }
        case Card::Face::Five: {
            std::cout << "5";
            break;
        }
        case Card::Face::Six: {
            std::cout << "6";
            break;
        }
        case Card::Face::Seven: {
            std::cout << "7";
            break;
        }
        case Card::Face::Eight: {
            std::cout << "8";
            break;
        }
        case Card::Face::Nine: {
            std::cout << "9";
            break;
        }
        case Card::Face::Ten: {
            std::cout << "10";
            break;
        }
        case Card::Face::J: {
            std::cout << "J";
            break;
        }
        case Card::Face::Q: {
            std::cout << "Q";
            break;
        }
        case Card::Face::K: {
            std::cout << "K";
            break;
        }
        case Card::Face::A: {
            std::cout << "A";
            break;
        }
    }
    switch (card.suit) {
        case Card::Suit::Clubs: {
            std::cout << "Clubs\n";
            break;
        }
        case Card::Suit::Diamonds: {
            std::cout << "Diamonds\n";
            break;
        }
        case Card::Suit::Hearts: {
            std::cout << "Hearts\n";
            break;
        }
        case Card::Suit::Spades: {
            std::cout << "Spades\n";
            break;
        }
    }
    return os;
}

