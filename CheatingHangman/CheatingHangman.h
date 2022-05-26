#ifndef CHEATINGHANGMAN_CHEATINGHANGMAN_H
#define CHEATINGHANGMAN_CHEATINGHANGMAN_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

class CheatingHangman {

public:
    // Ctor will take in wordlist and set up game
    CheatingHangman(std::vector<std::string> initial_wordlist);

    // Determines if a user guess is valid
    bool is_valid_guess(std::string &letter);

    // Returns a bool for the gamestate if number of incorrect guessues reaches zero or if the user wins
    bool game_state();

    // Applies a valid guess, updating the wordlist through a map and the masking function
    std::map<std::string, std::vector<std::string>> apply_guess(std::string &letter);

    // Prints things like current hint, number of guesses remaining, and so forth
    void print_status();

    // Take in a word and guessed letters, then return the mask:
    // ie with input "aabcd" as word and "ac" as guesses, returns "aa_c_"
    std::string mask(std::string &word, std::string &letter);

    // Getters for test functions that you recommended
    std::vector<std::string> get_current_words();
    std::string get_current_hint();
    std::string set_current_hint(int word_length);

private:
    // Current set of words
    std::vector<std::string> wordlist;
    // Current guessed letters, in order of guessed (but order is not really important)
    std::string guessed_letters;
    // Time till game over
    int incorrect_guesses_remaining{5};
    // What is displayed to the user
    std::string current_hint;
};


#endif //CHEATINGHANGMAN_CHEATINGHANGMAN_H
