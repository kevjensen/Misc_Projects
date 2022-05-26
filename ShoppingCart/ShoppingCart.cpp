//
// Created by kev_j on 3/1/2020.
//

#include "ShoppingCart.h"
#include "Items.h"
#include "Porg.h"
#include "Naboofruit.h"
#include "Portionbread.h"
#include "DeathSticks.h"
#include "Jabajuice.h"

void ShoppingCart::additem(std::unique_ptr<Items> i) {
    // Adds item to shopping cart
    cart.push_back(std::move(i));
}


void ShoppingCart::contents() {
    std::cout << "Your shopping cart contains:\n";

    // Ranged for loop to print off elements pushed to vector
    for (const auto & i : cart) {
        std::cout << i->name() << "\n";
    }
}

void ShoppingCart::checkout() {
    std::cout << "Your shopping cart contains:\n";
    total = 0;

    // Prints out name, price, and aggregate price of entire cart with tax
    for (const auto & i : cart) {
        std::cout << i->name() << " " << i->price() << " Galactic Standard Credits\n";
        total += i->price();
        total = total + (total * .06);
    }

    std::cout << "Total: " << total << " Galactic Standard Credits\n";
}

void ShoppingCart::list() {

    // Instantiate objects of each subclass to print names
    Porg porg;
    Naboofruit nbf;
    Portionbread pb;
    DeathSticks ds;
    Jabajuice jj;

    std::cout << "Please select an option from the current menu:\n" << porg.name() << "\n" << nbf.name() << "\n" <<
    pb.name() << "\n" << ds.name() << "\n" << jj.name() << "\n";


}
