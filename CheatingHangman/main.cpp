#include <iostream>
#include <fstream>
#include "CheatingHangman.h"

std::string user_input();

void test_mask();

void test_apply_guess();

std::vector<std::string> read_file(std::string wordfile);

int main() {

    //test_apply_guess();
    //test_mask();
    // Read in the word list here to be used in the parameter list for the ctor
    std::vector<std::string> biglist = read_file("words_alpha.txt");
    std::vector<std::string> wordlist;

    // Initialize string for guessed letters
    std::string guess;

    // Read in an empty map for the print status; map will be updated in the game loop
    std::map<std::string, std::vector<std::string>> partitions;

    // Initialize word_length for user_input
    int word_length = 0;

    //test_mask();
    //test_partition();

    // Prompts user for their desired word list and then removes any words from the
    // big list that don't have that length
    for (;;) {
        std::cout << "What word length do you want? Number between 1 and 6.\n";
        std::cin >> word_length;
        if (word_length == 0 || word_length > 6) {
            std::cout << "Invalid input. Please try again\n";
        } else {
            for (int i = 0; i < biglist.size(); ++i) {
                if (biglist[i].length() == word_length) {
                    wordlist.push_back(biglist[i]);
                }
            }
            break;
        }
    }

    // Instantiates an object to play the game
    CheatingHangman ch(wordlist);
    ch.set_current_hint(word_length);

    // Game loop
    while (ch.game_state() == true) {

        // Prints out number of words,
        ch.print_status();

        // Prompts the user for their guessed letter
        for (;;) {
            guess = user_input();
            if (!ch.is_valid_guess(guess)) {
                std::cout << "Incorrect input. Please try again.\n";
            } else {
                std::cout << "You have guessed '" << guess << "'\n";
                break;
            }
        }
        partitions = ch.apply_guess(guess);
        std::cout << "The partite sets from your guess are:\n";
        for (const auto &i : partitions) {
            std::cout << i.first << ": ";
            for (const auto &j : i.second) {
                std::cout << j << ", ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}

std::string user_input() {
    std::string guess;
    std::cout << "What letter do you want to guess?\n";
    std::cin >> guess;
    // Tried using a ranged-for loop but couldn't return a lower-case letter for some reason. The normal for-loop
    // made it easier to just change the letter at a specific index
    for (int i = 0; i < guess.length(); ++i) {
        if (isupper(guess[i]) == true) {
            guess[i] = tolower(guess[i]);
        }
    }
    return guess;
}

std::vector<std::string> read_file(std::string wordfile) {
    // Declare container for wordlist
    std::vector<std::string> wordlist;
    std::ifstream in(wordfile);

    // Reads each line of the file, adding each line to a
    // a place in the vector
    while (std::getline(in, wordfile)) {
        wordlist.push_back(wordfile);
    }
    in.close();
    return wordlist;
}

void test_mask() {
    {
        std::vector<std::string> wordlist;
        wordlist.emplace_back("dbakda");
        CheatingHangman b(wordlist);
        std::string word = "dbakda";
        std::string guesses = "a";
        std::string expected = "__a__a";
        std::string result = b.mask(word, guesses);
        if (result != expected) {
            std::cout << "Mask error word = " << word << " guesses = " << guesses
                      << " expected = " << expected << " result = " << result << "\n";
        }
    }
    {
        std::vector<std::string> wordlist;
        wordlist.emplace_back("ababcc");
        CheatingHangman b(wordlist);
        std::string word = "ababcc";
        std::string guesses = "ab";
        std::string expected = "abab__";
        std::string result = b.mask(word, guesses);
        if (result != expected) {
            std::cout << "Mask error word = " << word << " guesses = " << guesses
                      << " expected = " << expected << " result = " << result << "\n";
        }
    }
    {
        std::vector<std::string> wordlist;
        wordlist.emplace_back("ababcc");
        CheatingHangman b(wordlist);
        std::string word = "ababcc";
        std::string guesses = "abc";
        std::string expected = "ababcc";
        std::string result = b.mask(word, guesses);
        if (result != expected) {
            std::cout << "Mask error word = " << word << " guesses = " << guesses
                      << " expected = " << expected << " result = " << result << "\n";
        }
    }
}

void test_apply_guess() {
    {
        std::vector<std::string> input_wordlist = {"aa", "ab", "ac"};
        std::string guess = "a";
        std::string expected_hint = "a_";
        std::vector<std::string> expected_words = {"ab", "ac"};

        CheatingHangman test{input_wordlist};
        test.apply_guess(guess);

        std::vector<std::string> actual_words = test.get_current_words();
        std::string actual_hint = test.get_current_hint();

        if (actual_words != expected_words || actual_hint != expected_hint) {
            std::cout << "apply_guess error: input_wordlist = {";
            for (auto i : input_wordlist) {
                std::cout << i << ", ";
            }
            std::cout << "} guess = " << guess << " expected_hint = " << expected_hint
                      << " actual_hint = " << actual_hint << " expected_words = {";
            for (auto i : expected_words) {
                std::cout << i << ", ";
            }
            std::cout << "} actual_words = {";
            for (auto i : actual_words) {
                std::cout << i << ", ";
            }
            std::cout << "}\n";
        }
    }
}