//
// Created by kev_j on 3/1/2020.
//

#ifndef UNTITLED5_SHOPPINGCART_H
#define UNTITLED5_SHOPPINGCART_H

#include "Items.h"

#include <vector>
#include <iostream>
#include <string>
#include <memory>

class ShoppingCart {

public:

    ShoppingCart () = default;
    // Will add an object of class Item to the shopping cart vector
    void additem (std::unique_ptr<Items> i);
    // Will allow a user to check the contents of their shopping cart
    void contents ();
    // Will print the total, with tax
    void checkout ();
    // Will show the menu at the store
    void list();


private:
    // This vector stores elements of type Items
    std::vector<std::unique_ptr<Items>> cart;
    // Initialize the total value of the shopping cart here to 0
    double total{0};

};


#endif //UNTITLED5_SHOPPINGCART_H
