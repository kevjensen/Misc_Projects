//
// Created by kev_j on 2/3/2020.
//

#ifndef VIGENERECIPHER_CRYPTO_H
#define VIGENERECIPHER_CRYPTO_H

#include "Letter.h"

class Crypto {
public:
    // Crypto Constructor
    Crypto ();

    // Functions to read the respective file and put it into a string
    std::string read_file_encrypt(const std::string &filename);
    std::string read_file_decrypt(const std::string &filename);

    // Function that prompts for the user defined cipher
    std::string key();

    // Encrypts the plain text into an encrypted string
    std::string encrypt(const std::string &plain_txt, const std::string &key);

    // Decrypts the encrypted text into a decrypted string
    std::string decrypt(const std::string &encrypted, const std::string &key);

    // Writes the respective string into a text file
    void write_file(const std::string &filename, const std::string &encoded);

    // Compares the original text file to the decrypted text file
    void compare_files(const std::string& decryption, const std::string& plain);

    // Tests
    void test_encryption();
    void test_decryption();

private:
    std::string decrypted_file;
    std::string encrypted_file;
    std::string cipher;
    std::string cipher_input;
    std::string plain_file;
    int truth_value;
};


#endif //VIGENERECIPHER_CRYPTO_H
