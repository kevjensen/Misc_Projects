//
// Created by kev_j on 2/3/2020.
//

#include <fstream>
#include "Crypto.h"


std::string Crypto::read_file_encrypt(const std::string &filename) {
    std::ifstream in(filename);

    // Reads the file character by character
    while (!in.eof()) {
        // Read a single character
        char c = in.get();

        if (in.gcount() != 1) {
            // Hit EOF
            break;
        }

        plain_file += c;
    }
    in.close();

    return plain_file;
}

std::string Crypto::read_file_decrypt(const std::string &filename) {
    std::ifstream in(filename);

    // Reads the file character by character
    while (!in.eof()) {
        // Read a single character
        char c = in.get();

        if (in.gcount() != 1) {
            // Hit EOF
            break;
        }

        decrypted_file += c;
    }

    in.close();

    return decrypted_file;
}

void Crypto::compare_files(const std::string &decryption, const std::string &plain) {
    // Compares the two files together to determine if they are the same or not
    if (decryption != plain) {
        std::cout << "Error: Expected files to match.";
    } else {
        std::cout << "Files match. Encryption and decryption successful.";
    }
}

Crypto::Crypto() {
    // User provides cipher
    key();

    // Read in the plain text
    read_file_encrypt("Plain_txt.txt");

    // Encrypt the plain text with the user provided cipher
    encrypt(plain_file, cipher);

    // Writes the encrypted string to a temporary file
    write_file("encrypted.txt", encrypted_file);

    // Read the encrypted file into a string for decryption
    read_file_decrypt("encrypted.txt");

    // Decrypts the encrypt string
    decrypt(decrypted_file, cipher);

    // Writes the decrypted string to a file
    write_file("reverted.txt", decrypted_file);

    // Compares the the original text and the text that went through encryption/decryption
    compare_files("reverted.txt", "Plain_txt.txt");
}

std::string Crypto::key() {
    for (;;) {

        // Prompts user to input key for cipher
        std::cout
                << "Please enter the key for cipher. "
                   "Code must be only alphabetical letters and between 2-6 letters long.\n";
        std::cin >> cipher_input;

        // Checks cipher for appropriate length and characters; I use the truth_value to
        // navigate scoping issues that I was having
        truth_value = 0;
        for (char c : cipher_input) {
            if (cipher_input.length() > 6 || cipher_input.length() < 2) {
                std::cout << "Invalid cipher. Try again.\n";
                truth_value = 1;
                break;
            }
            if (!isalpha(c)) {
                std::cout << "Invalid cipher. Try again.\n";
                truth_value = 1;
                // I clear the cipher for an invalid entry otherwise whatever was entered and stored will carry
                // over to the next entry
                cipher.clear();
                break;
            } else {
                cipher += cipher_input;
            }
        }
        if (truth_value == 0) {
            return cipher;
        }
    }
}


void Crypto::write_file(const std::string &filename, const std::string &cryption) {
    std::ofstream out(filename);

    if (!out.is_open()) {
        throw std::runtime_error("Could not open file to write to");
    }

    out << cryption;
    std::cout << cryption;
    out.close();
}

void Crypto::test_encryption() {
    {
        encrypt("The quick brown fox jumps over the lazy dog.", "Secret");
        if (encrypted_file != "Llg hybuo dispf jqo nnetu fzxj xjv ptrc ffk.") {
            std::cout << "Error. Expected: Llg hybuo dispf jqo nnetu fzxj xjv ptrc ffk. Got: " <<
                      encrypt("The quick brown fox jumps over the lazy dog.", "Secret") << "\n";
        } else {
            std::cout << "Test correct: " << encrypted_file << "\n";
        }
        // Need to clear the encrypted_file for subsequent tests since it is a class variable
        encrypted_file.clear();
    }
    {
        encrypt("The world is changed.", "Sword");
        if (encrypted_file != "Lds nrjhr zv udoejwz.") {
            std::cout << "Error. Expected: Lds nrjhr zv udoejwz. Got: " <<
                      encrypt("The world is changed.", "Sword") << "\n";
        } else {
            std::cout << "Test correct: " << encrypted_file << "\n";
        }
        encrypted_file.clear();
    }
    {
        encrypt("Much that once was was lost.", "Sword");
        if (encrypted_file != "Eqqy wzwh fqua krv owg crkp.") {
            std::cout << "Error. Expected: Eqqy wzwh fqua krv owg crkp. Got: " <<
                      encrypt("Much that once was was lost.", "Sword") << "\n";
        } else {
            std::cout << "Test correct: " << encrypted_file << "\n";
        }
        encrypted_file.clear();
    }
    {
        encrypt("This is some gouda cheese.", "Puns");
        if (encrypted_file != "Ibvk xm fgby tgjxn uwyrkt.") {
            std::cout << "Error. Expected: Ibvk xm fgby tgjxn uwyrkt. Got: " <<
                      encrypt("This is some gouda cheese.", "Puns") << "\n";
        } else {
            std::cout << "Test correct: " << encrypted_file << "\n";
        }
        encrypted_file.clear();
    }
    {
        encrypt("T!e!s@t s)y&m*o$l%s", "LIFE");
        if (encrypted_file != "E!m!x@x d)g&r*s$w%a") {
            std::cout << "Error. Expected: E!m!x@x d)g&r*s$w%a Got: " <<
                      encrypt("T!e!s@t s)y&m*o$l%s", "LIFE") << "\n";
        } else {
            std::cout << "Test correct: " << encrypted_file << "\n";
        }
        encrypted_file.clear();
    }
    {
        encrypt("T!e!s@t s)y&m*o$l%s", "LIFE");
        if (encrypted_file != "E!m!x@x d)g&r*s$w%a") {
            std::cout << "Error. Expected: E!m!x@x d)g&r*s$w%a Got: " <<
                      encrypt("T!e!s@t s)y&m*o$l%s", "LIFE") << "\n";
        } else {
            std::cout << "Test correct: " << encrypted_file << "\n";
        }
        encrypted_file.clear();
    }
    {
        encrypt("tHe CaT wEnT HaYwIrE tOdAy!!!!!!", "Longerkey");
        if (encrypted_file != "eVr IeK gIlE VnEaZbI rZrNe!!!!!!") {
            std::cout << "Error. Expected: eVr IeK gIlE VnEaZbI rZrNe!!!!!! Got: " <<
                      encrypt("tHe CaT wEnT HaYwIrE tOdAy!!!!!!", "Longerkey") << "\n";
        } else {
            std::cout << "Test correct: " << encrypted_file << "\n";
        }
        encrypted_file.clear();
    }
}

void Crypto::test_decryption() {
    {
        decrypt("Llg hybuo dispf jqo nnetu fzxj xjv ptrc ffk.", "Secret");
        if (decrypted_file != "The quick brown fox jumps over the lazy dog.") {
            std::cout << "Error. Expected: The quick brown fox jumps over the lazy dog. Got: " <<
                      decrypt("Llg hybuo dispf jqo nnetu fzxj xjv ptrc ffk.", "Secret") << "\n";
        } else {
            std::cout << "Test correct: " << decrypted_file << "\n";
        }
        decrypted_file.clear();
    }
    {
        decrypt("Hvl jmu dlc nvviovx gpzgf zlv bsyo?", "Longerkey");
        if (decrypted_file != "Why did the chicken cross the road?") {
            std::cout << "Error. Expected: Why did the chicken cross the road? Got: " <<
                      decrypt("Hvl jmu dlc nvviovx gpzgf zlv bsyo?", "Longerkey") << "\n";
        } else {
            std::cout << "Test correct: " << decrypted_file << "\n";
        }
        decrypted_file.clear();
    }
    {
        decrypt("Scj? Sytr? Amzr? Puycn? E? UZCQILLMOASIPQMW... KAMZRPNYTUGMFZQILLMO++UZCQ??", "Longerkey");
        if (decrypted_file != "How? Much? Wood? Could? A? WOODCHUCKCHUCKIF... AWOODCHUCKCOULDCHUCK++WOOD??") {
            std::cout
                    << "Error. Expected: How? Much? Wood? Could? A? WOODCHUCKCHUCKIF... AWOODCHUCKCOULDCHUCK++WOOD?? Got: "
                    <<
                    decrypt("Scj? Sytr? Amzr? Puycn? E? UZCQILLMOASIPQMW... KAMZRPNYTUGMFZQILLMO++UZCQ??", "Longerkey")
                    << "\n";
        } else {
            std::cout << "Test correct: " << decrypted_file << "\n";
        }
        decrypted_file.clear();
    }
    {
        decrypt("Scj? Sytr? Amzr? Puycn? E? UZCQILLMOASIPQMW... KAMZRPNYTUGMFZQILLMO++UZCQ??", "Longerkey");
        if (decrypted_file != "How? Much? Wood? Could? A? WOODCHUCKCHUCKIF... AWOODCHUCKCOULDCHUCK++WOOD??") {
            std::cout
                    << "Error. Expected: How? Much? Wood? Could? A? WOODCHUCKCHUCKIF... AWOODCHUCKCOULDCHUCK++WOOD?? Got: "
                    <<
                    decrypt("Scj? Sytr? Amzr? Puycn? E? UZCQILLMOASIPQMW... KAMZRPNYTUGMFZQILLMO++UZCQ??", "Longerkey")
                    << "\n";
        } else {
            std::cout << "Test correct: " << decrypted_file << "\n";
        }
        decrypted_file.clear();
    }
    {
        decrypt("Ayw ku yfnd lbvu ipf srouoe?", "EricCartman");
        if (decrypted_file != "Who is your lord and savior?") {
            std::cout << "Error. Expected: Who is your lord and savior? Got: " <<
                      decrypt("Ayw ku yfnd lbvu ipf srouoe?", "EricCartman") << "\n";
        } else {
            std::cout << "Test correct: " << decrypted_file << "\n";
        }
        decrypted_file.clear();
    }
    {
        decrypt("Ohnz wwysjs qu Tmovss fky?", "Sanguine");
        if (decrypted_file != "What colors do Zebras see?") {
            std::cout << "Error. Expected: What colors do Zebras see? Got: " <<
                      decrypt("Ohnz wwysjs qu Tmovss fky?", "Sanguine") << "\n";
        } else {
            std::cout << "Test correct: " << decrypted_file << "\n";
        }
        decrypted_file.clear();
    }
}

std::string Crypto::encrypt(const std::string &plain_txt, const std::string &key) {
    int key_index = 0;
    for (char c : plain_txt) {
        if (isalpha(c)) {
            Letter l = c;
            Letter encrypted_char = l + static_cast<Letter>(key[key_index]);
            encrypted_file += encrypted_char;
            key_index = (key_index + 1) % key.length();
        } else {
            encrypted_file += c;
        }
    }
    return encrypted_file;
}

std::string Crypto::decrypt(const std::string &encrypted, const std::string &key) {
    int key_index = 0;
    for (char c : encrypted) {
        if (isalpha(c)) {
            Letter l = c;
            Letter decrypted_char = l - static_cast<Letter>(key[key_index]);
            decrypted_file += decrypted_char;
            key_index = (key_index + 1) % key.length();
        } else {
            decrypted_file += c;
        }
    }
    return decrypted_file;
}
