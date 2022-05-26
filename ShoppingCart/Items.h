//
// Created by kev_j on 3/1/2020.
//

#ifndef UNTITLED5_ITEMS_H
#define UNTITLED5_ITEMS_H

//#include "ShoppingCart.h"

#include <string>

class Items {
public:

    // Rule of 0 compliant

    // Pure virtual functions for child classes to override
    virtual std::string name() const = 0;
    virtual double price() const = 0;
};


#endif //UNTITLED5_ITEMS_H
