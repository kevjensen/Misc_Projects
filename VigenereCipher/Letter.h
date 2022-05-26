//
// Created by kev_j on 2/3/2020.
//

#ifndef VIGENERECIPHER_LETTER_H
#define VIGENERECIPHER_LETTER_H

#include <string>
#include <iostream>
#include <ostream>
#include <string>
#include <list>
#include "Crypto.h"

class Letter {

public:

    // Constructor that handles letters
    Letter (char a);
    // Letter test functions for addition and subtraction
    void test_letter_add();
    void test_letter_sub();
    // Operator Overloads
    friend Letter operator+(const Letter &lhs, const Letter &rhs);
    friend Letter operator-(const Letter &lhs, const Letter &rhs);
    friend bool operator !=(const Letter &lhs, const Letter &rhs);
    friend bool operator ==(const Letter &lhs, const Letter &rhs);
    friend std::string operator +=(std::string &lhs, Letter &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Letter &rhs);
private:
    // Data member
    char a;
};




#endif //VIGENERECIPHER_LETTER_H
