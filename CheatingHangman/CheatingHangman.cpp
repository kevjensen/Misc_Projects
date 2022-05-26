#include "CheatingHangman.h"

void CheatingHangman::print_status() {
    std::cout << "The possible words are: ";
    for (const auto &i : wordlist) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout << "There are " << wordlist.size() << " words remaining.\n";
    std::cout << "You have " << incorrect_guesses_remaining << " incorrect guesses remaining.\n";
    std::cout << "Current hint is: " << current_hint << "\n";
    if (!guessed_letters.empty()) {
        std::cout << "Guessed letters: " << guessed_letters << "\n";
    }
}

std::map<std::string, std::vector<std::string>> CheatingHangman::apply_guess(std::string &letter) {
    std::map<std::string, std::vector<std::string>> partitions;
    std::string new_hint;
    int current_max = 0;

    guessed_letters += letter;
    // Push words from wordlist to the map with the masked from as a key
    for (int i = 0; i < wordlist.size(); ++i) {
        partitions[mask(wordlist[i], guessed_letters)].push_back(wordlist[i]);
    }
    // Ranged-for loop through the new partitions map to find the key-value with the largest size
    // to use as the
    for (const auto &c : partitions) {
        if (c.second.size() > current_max) {
            current_max = c.second.size();
            new_hint = c.first;
            wordlist = c.second;
        }
    }
    if (new_hint != current_hint) {
        // successful guesses
        current_hint = new_hint;
        //wordlist = partitions[new_hint];
    }
    if (new_hint == current_hint) {
        std::cout << "Unfortunately, '" << letter << "' is not in the word.\n";
        -- incorrect_guesses_remaining;
    }
    return partitions;
}


std::string CheatingHangman::mask(std::string &word, std::string &letter) {
    std::string maskstr;
    // For each letter in the word, loop through the guessed_letters
    // and apply the letter if it matches or an underscore if it does not
    for (int i = 0; i < word.size(); ++i) {
        for (auto let : letter) {
            if (let == word[i]) {
                maskstr.push_back(let);
            }
        }
        if (maskstr.size() == i) {
            maskstr.push_back('_');
        }
    }
    return maskstr;
}

CheatingHangman::CheatingHangman(std::vector<std::string> initial_wordlist) :
        wordlist{initial_wordlist} {

}

bool CheatingHangman::is_valid_guess(std::string &letter) {
    if (letter.length() != 1) {
        return false;
    }
    for (auto c : letter) {
        if (!isalpha(c)) {
            return false;
        }
        for (char let : guessed_letters) {
            if (let == letter[0]) {
                return false;
            }
        }
    }
    return true;
}

bool CheatingHangman::game_state() {

    // End game if incorrect guesses remaining equals 0
    if (incorrect_guesses_remaining == 0) {
        std::cout << "You have run out of guesses and have lost.";
        return false;
    }
    // Loop through current_hint and if any character is an underscore then the game continues
    for (const auto &c : current_hint) {
        if (c == '_') {
            return true;
        }
    }
    std::cout << "Congrats! " << current_hint << " was the word!";
}

std::string CheatingHangman::get_current_hint() {
    return current_hint;
}

std::vector<std::string> CheatingHangman::get_current_words() {
    return wordlist;
}

std::string CheatingHangman::set_current_hint(int word_length) {
    // Initializes the current_hint based on the word length that a user inputs to start the game
    for (int i = 0; i < word_length; ++i) {
        current_hint.push_back('_');
    }
    return current_hint;
}
