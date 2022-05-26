#include "ShoppingCart.h"
#include "Weighted.h"
#include "DeathSticks.h"
#include "Jabajuice.h"
#include "Portionbread.h"
#include "Porg.h"
#include "Naboofruit.h"


void shopping_program(ShoppingCart &cart);

void tests();

int main() {

    // Tests to verify the functionality of shopping cart functions
    // tests();

    // Instantiates an object of class ShoppingCart to read into the shopping_program
    ShoppingCart cart;

    // I placed this prompt outside of the shopping program because it was just a lot of stuff to print
    // every time the program looped through
    std::cout << "Welcome to a grocery store from a galaxy far, far away. You may input the commands 'cart' to "
                 "see the contents of your shopping cart, 'list' to see the menu"
                 " and 'checkout' to terminate the program.\n The program is not case sensitive but it is space sensitive"
                 " according to how the item is displayed on the menu.\n\n";

    shopping_program(cart);

    return 0;
}

void shopping_program(ShoppingCart &cart) {

    // String that takes in user input
    std::string user_i;

    while (user_i != "checkout") {
        // Takes in user input; use getline to account for whitespace in my titles
        std::getline(std::cin, user_i);

        // Set the string to lower to remove case sensitivity from user input
        for (auto &i : user_i) {
            i = static_cast<char>(tolower(i));
        }
        // These check the user input and either add an item, return a command, or return an error if the user input
        // does not match any of the program's commands
        if (user_i == "deathsticks") {
            // Add item to cart
            cart.additem(std::make_unique<DeathSticks>());
            std::cout << "Deathsticks added to cart.\n";
        } else if (user_i == "jaba juice") {
            // Add item to cart
            cart.additem(std::make_unique<Jabajuice>());
            std::cout << "Jaba juice added to cart.\n";
        } else if (user_i == "portion bread") {
            // Add item to cart
            cart.additem(std::make_unique<Portionbread>());
            std::cout << "Portion bread added to cart.\n";
        } else if (user_i == "porg") {
            double weight;
            std::cout << "How many pounds of porg would you like? Please input a number, not a word.\n";
            std::cin >> weight;
            // Removes extraneous empty line from my getline that was causing issues
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Add item to cart
            cart.additem(std::make_unique<Porg>(weight));
            std::cout << weight << " pounds of Porg added to cart.\n";
        } else if (user_i == "naboo fruit") {
            double weight;
            std::cout << "How many pounds of Naboo fruit would you like? Please input a number, not a word.\n";
            std::cin >> weight;
            // Removes extraneous empty line from my getline that was causing issues
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // Add item to cart
            cart.additem(std::make_unique<Naboofruit>(weight));
            std::cout << weight << " pounds of Naboo Fruit added to cart.\n";
        } else if (user_i == "cart") {
            // Check contents of cart
            cart.contents();
        } else if (user_i == "list") {
            // Display the list
            cart.list();
        } else if (user_i == "checkout") { // Runs the checkout program when prompted and terminates the program
            cart.checkout();
        } else {
            // If no entry fits, print invalid and prompt again
            std::cout << "Invalid command. Please try again.\n";
        }
    }
}

void tests() {
    {
        ShoppingCart cart;
        cart.contents();
    }
    {
        ShoppingCart cart;
        cart.list();
    }
    {
        ShoppingCart cart;
        cart.checkout();
    }
    {
        ShoppingCart cart;
        cart.list();
        cart.additem(std::make_unique<Portionbread>());
        cart.contents();
        cart.checkout();
    }
    {
        ShoppingCart cart;
        cart.list();
        cart.additem(std::make_unique<Porg>(1));
        cart.contents();
        cart.checkout();
    }
    {
        ShoppingCart cart;
        cart.list();
        cart.additem(std::make_unique<Jabajuice>());
        cart.additem(std::make_unique<Porg>(1));
        cart.contents();
        cart.checkout();
    }
}