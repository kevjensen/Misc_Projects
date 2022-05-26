//
// Created by kev_j on 2/3/2020.
//

#include "Letter.h"

Letter operator+(const Letter &lhs, const Letter &rhs) {
    // Convert from ASCII to and encrypt
    char cipher = ((static_cast<char>((std::tolower(lhs.a) - 'a') + (std::tolower(rhs.a) - 'a'))) % 26);
    // Convert back
    if (std::isupper(lhs.a)) {
        cipher += 'A';
    } else {
        cipher += 'a';
    }
    return Letter{cipher};
}

Letter operator-(const Letter &lhs, const Letter &rhs) {
    // Convert from ASCII to alphabetic
    char cipher = (((static_cast<char>(std::tolower(lhs.a) - std::tolower(rhs.a) + 26) % 26)));
    // Convert from alphabetic to ASCII
    if (std::isupper(lhs.a)) {
        cipher += 'A';
    } else {
        cipher += 'a';
    }
    return Letter{cipher};
}

bool operator !=(const Letter &lhs, const Letter &rhs) {
    return lhs.a != rhs.a;
}

bool operator ==(const Letter &lhs, const Letter &rhs) {
    return lhs.a == rhs.a;
}

std::string operator +=(std::string &lhs, Letter &rhs) {
    return lhs += rhs.a;
}

Letter::Letter(char a_) : a(a_) {

}

void Letter::test_letter_add() {
    {
        Letter plain{'H'};
        Letter key{'K'};
        Letter cipher{'R'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'h'};
        Letter key{'k'};
        Letter cipher{'r'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'G'};
        Letter key{'J'};
        Letter cipher{'P'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'g'};
        Letter key{'j'};
        Letter cipher{'p'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'g'};
        Letter key{'k'};
        Letter cipher{'q'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'a'};
        Letter key{'b'};
        Letter cipher{'b'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'b'};
        Letter key{'z'};
        Letter cipher{'a'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'Z'};
        Letter key{'Z'};
        Letter cipher{'Y'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'T'};
        Letter key{'W'};
        Letter cipher{'P'};
        if (cipher != plain + key) {
            std::cout << "Error: " << plain << " + " << key << " = " << plain + key << " Expected " << cipher;
        }
    }
}

void Letter::test_letter_sub() {
    {
        Letter plain{'a'};
        Letter key{'b'};
        Letter cipher{'z'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'a'};
        Letter key{'j'};
        Letter cipher{'r'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'b'};
        Letter key{'j'};
        Letter cipher{'s'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'c'};
        Letter key{'u'};
        Letter cipher{'i'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
            std::cout << plain - key;
        }
    }
    {
        Letter plain{'C'};
        Letter key{'U'};
        Letter cipher{'I'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'C'};
        Letter key{'u'};
        Letter cipher{'I'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'a'};
        Letter key{'U'};
        Letter cipher{'g'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'a'};
        Letter key{'b'};
        Letter cipher{'z'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
    {
        Letter plain{'c'};
        Letter key{'O'};
        Letter cipher{'o'};
        if (cipher != plain - key) {
            std::cout << "Error: " << plain << " - " << key << " = " << plain - key << " Expected " << cipher;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Letter &rhs) {
    os << rhs.a;
    return os;
}
