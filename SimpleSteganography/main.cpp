#include <iostream>
#include <cctype>
#include <cstdint>
#include <string>
#include <fstream>
#include <stdexcept>

std::string encode_char(std::string block, char payload);

void test_encode_char();

char decode_char(std::string block);

void test_decode_char();

int find_boundary(std::string message, int start);

void test_find_boundary();

std::string encode_string(std::string message, std::string payload);

void test_encode_string();

std::string decode_string(std::string message);

void test_decode_string();

std::string read_file(std::string filename);

void write_file(std::string filename, std::string message);

int main() {
    // Main function
    std::string message = read_file("beowulf.txt");
    std::string payload = read_file("payload.txt");
    std::string encoded = encode_string(message, payload);
    write_file("encoded.txt", encoded);
    std::string decoded = read_file("encoded.txt");
    std::string recovered = decode_string(decoded);
    std::cout << recovered << std::endl;
}

std::string encode_char(std::string block, char payload) {
    int current = 0;
    int length = block.length();

    for (int offset = 7; offset >= 0; --offset) {
        // Find the next alphabetic character
        while (!std::isalpha(block[current]) && current < length) {
            ++current;
        }
        // Ensure we haven't walked past the end of the block
        if (current >= length) {
            throw std::runtime_error("Ran past length");
        }
        // Fix the output case
        if (uint8_t(payload) >> offset & uint8_t(0x1)) {
            block[current] = std::toupper(block[current]);
        } else {
            block[current] = std::tolower(block[current]);
        }
        ++current;
    }
    return block;
}

void test_encode_char() {
    // Simple cases
    if (encode_char("abcdefgh", 'A') != "aBcdefgH") {
        std::cout << "Error: In encode char, input 'abcdefgh', 'A' returned '" <<
                  encode_char("abcdefgh", 'A') << "'\n";
    }
    if (encode_char("abcdefgh", 'a') != "aBCdefgH") {
        std::cout << "Error: In encode char, input 'abcdefgh', 'a' returned '" <<
                  encode_char("abcdefgh", 'a') << "'\n";
    }
    if (encode_char("a b c d e f g h", 'A') != "a B c d e f g H") {
        std::cout << "Error: In encode char, input 'a b c d e f g h', 'A' returned '"
                  << encode_char("a b c d e f g h", 'A') << "'\n";
    }
    if (encode_char("a\tbcdefgh", 'A') != "a\tBcdefgH") {
        std::cout << "Error: In encode char, input 'a\tbcdefgh', 'A' returned '"
                  << encode_char("a\tbcdefgh", 'A') << "'\n";
    }
    if (encode_char("a\nbcdefgh", 'A') != "a\nBcdefgH") {
        std::cout << "Error: In encode char, input 'a\nbcdefgh', 'A' returned '"
                  << encode_char("a\nbcdefgh", 'A') << "'\n";
    }
}

char decode_char(std::string block) {
    char ret = 0;
    int remaining = 8; // number of letters we are still looking for

    // Go through every character in the message
    for (char c : block) {
        if (std::isalpha(c)) {
            --remaining;
            // If it is upper case, that indicates a 1.
            if (std::isupper(c)) {
                ret |= 1 << remaining;
            }
            // If we found all the bits we are looking for, stop
            if (remaining == 0) {
                break;
            }
        }
    }
    if (remaining > 0) {
        throw std::runtime_error("Not all characters found.");
    }
    return ret;
}

void test_decode_char() {
    if (decode_char("aBcdefgH") != 'A') {
        std::cout << "Decode error: decode returned " <<
                  decode_char("aBcdefgH") << "\n";
    }
    if (decode_char("aBCdefgH") != 'a') {
        std::cout << "Decode error: decode returned "
                  << decode_char("aBCdefgH") << "\n";
    }
    if (decode_char("a B c d e f g H") != 'A') {
        std::cout << "Decode error (space A): decode returned "
                  << decode_char("a B c d e f g H") << "\n";
    }
}


int find_boundary(std::string message, int start) {
    // Count how many characters after start you need to travel to
    // find 8 alphabetic characters
    // If not enough are found, return -1

    int offset = 0;
    int remaining = 8;
    while (remaining > 0) {
        if ((start + offset) >= message.length()) {
            return -1;
        }
        if (std::isalpha(message[start + offset])) {
            --remaining;
        }
        ++offset;
    }
    return offset;
}

void test_find_boundary() {
    if (find_boundary("abcdefgh", 0) != 8) {
        std::cout << "Error: test_find_boundary returned " <<
                  find_boundary("abcdefgh", 0) << "\n";
    }
    if (find_boundary("abc   defgh", 0) != 11) {
        std::cout << "Error: test_find_boundary returned "
                  << find_boundary("abcdefgh", 0) << "\n";
    }
    if (find_boundary("Few quips galvanized the mock "
                      "jury box.", 0) != 9) {
        std::cout << "Error: test_find_boundary returned "
                  << find_boundary("abcdefgh", 0) << "\n";
    }
    if (find_boundary("xxxabcdefgh", 3) != 8) {
        std::cout << "Error: test_find_boundary returned "
                  << find_boundary("abcdefgh", 0) << "\n";
    }
    if (find_boundary("Few quips galvanized the mock jury box.", 18) != 10) {
        std::cout << "Error: test_find_boundary returned "
                  << find_boundary("abcdefgh", 0) << "\n";
    }
}

std::string encode_string(std::string message, std::string payload) {
    std::string ret = "";
    int start = 0;

    // Encode the payload
    for (char c : payload) {
        //for (int c = 0; c < payload.length(); ++c) {
        int block_length = find_boundary(message, start);
        if (block_length == -1) {
            throw std::runtime_error("Block length incorrect");
        }
        std::string block = message.substr(start, block_length);
        ret += encode_char(block, c);
        start += block_length;
    }

    // Encode a null terminator
    int block_length = find_boundary(message, start);
    if (block_length == -1) {
        throw std::runtime_error("Block length incorrect.");
    }
    std::string block = message.substr(start, block_length);
    ret += encode_char(block, '\0');
    start += block_length;

    // Add remainder of message
    std::string remainder = message.substr(start, message.length());
    ret += message.substr(start);

    return ret;
}

void test_encode_string() {
    if (encode_string("abcdefgh", "") != "abcdefgh") {
        std::cout << "Encode string error: encode string returned "
                  << encode_string("abcdefgh", "") << "\n";
    }
    if (encode_string("abcdefghstuvwxyz", "A") != "aBcdefgHstuvwxyz") {
        std::cout << "Encode string error: encode string returned "
                  << encode_string("abcdefghstuvwxyz", "A") << "\n";
    }
    if (encode_string("abcdefghstuvwxyz", "a") != "aBCdefgHstuvwxyz") {
        std::cout << "Encode string error: encode string returned "
                  << encode_string("abcdefghstuvwxyz", "a") << "\n";
    }
    if (encode_string("Few quips galvanized the mock jury box.", "Hi!") !=
        "fEw qUips gALvAniZed The moCk jury box.") {
        std::cout << "Encode string error: encode string returned "
                  << encode_string("Few quips galvanized the mock jury box.", "Hi!") << "\n";
    }
    if (encode_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "A") !=
        "aBcdefgHijklmnopQRSTUVWXYZ") {
        std::cout << "Encode string error: encode string returned "
                  << encode_string("ABCDEFGHIJKLMNOPQRSTUVWXYZ", "A") << "\n";
    }
}

std::string decode_string(std::string message) {
    std::string ret = "";
    int start = 0;
    for (;;) {
        int block_length = find_boundary(message, start);

        // Ensure we have enough to make a block
        if (block_length == -1) {
            throw std::runtime_error("Block length incorrect.");
        }

        std::string block = message.substr(start, block_length);
        char c = decode_char(block);

        // Check for null terminator
        if (c == '\0') {
            break;
        }
        ret += c;
        start += block_length;
    }
    return ret;
}

void test_decode_string() {
    if (decode_string("aBcedefgHstuvwxyz") != "A") {
        std::cout << "Decode string error: decode string returned "
                  << decode_string("aBcdefgHstuvwxyz") << "\n";
    }
    if (decode_string("aBCdefgHstuvwxyz") != "a") {
        std::cout << "Decode string error: decode string returned "
                  << decode_string("aBCdefgHstuvwxyz") << "\n";
    }
    if (decode_string("fEw qUips gALvAniZed The moCk jury box.") != "Hi!") {
        std::cout << "Decode string error: decode string returned "
                  << decode_string("fEw qUips gALvAniZed The moCk jury box.") << "\n";
    }
    if (decode_string("aBcdefgHijklmnopQRSTUVWXYZ") != "A") {
        std::cout << "Decode string error: decode string returned "
                  << decode_string("aBcdefgHijklmnopQRSTUVWXYZ") << "\n";
    }
}

std::string read_file(std::string filename) {
    std::ifstream in(filename);

    if (!in.is_open()) {
        throw std::runtime_error("Couldn't open file");
    }

    std::string ret; // Declaring string to store file
    // Reads the file character by character
    while (!in.eof()) {
        // Read a single character
        char c = in.get();

        if (in.gcount() != 1) {
            // Hit EOF
            break;
        }

        ret += c;
    }
    in.close();

    return ret;
}

void write_file(std::string filename, std::string encoded) {
    std::ofstream out(filename);

    if (!out.is_open()) {
        throw std::runtime_error("Could not open file to write to");
    }

    out << encoded;

    out.close();
}

