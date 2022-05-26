//
// Created by kev_j on 1/21/2020.
//
#include <iostream>
#include <list>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

#ifndef WARGAME_CARD_H
#define WARGAME_CARD_H


class Card {
public:
    enum class Face {
        Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, J, Q, K, A
    };

    enum class Suit {
        Spades, Clubs, Hearts, Diamonds
    };


    Card (Face face, Suit suit);

    void card_test();

    Face face;
    Suit suit;

    // Operator Overloads
    friend bool operator<(const Card &lhs, const Card &rhs);
    friend bool operator>(const Card &lhs, const Card &rhs);
    friend bool operator==(const Card &lhs, const Card &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Card &card);
};



#endif //WARGAME_CARD_H
