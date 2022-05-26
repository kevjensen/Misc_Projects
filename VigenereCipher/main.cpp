#include <iostream>
#include "Letter.h"
#include "Crypto.h"
int main() {
    Letter b{'a'};
    b.test_letter_add();
    b.test_letter_sub();
    Crypto c;
    // c.test_encryption();
    // c.test_decryption();
    return 0;
}
