#include <iostream>
#include <cmath>

// Declarations
bool is_prime(int n);

bool is_left_truncatable(int n);

void build_truncatable_primes(int start);

int main() {

    std::cout << "The truncatable primes are:\n";
    build_truncatable_primes(2);
    build_truncatable_primes(3);
    build_truncatable_primes(5);
    build_truncatable_primes(7);

    return 0;
}

// Definitions
bool is_prime(int n) {

    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    //Naive trial division
    int sqrt_n = static_cast<int>(std::sqrt(n));

    for (int divisor = 2; divisor <= sqrt_n; ++divisor) {
        if (n % divisor == 0 || n % (divisor + 2) == 0) {
            // Found a divisor
            return false;
        }
    }
    // Found no divisor
    return true;
}

bool is_left_truncatable(int n) {
    for (int mod = 10; mod < n; mod *= 10) {
        if (!is_prime(n % mod)) {
            return false;
        }
        if (is_prime(n % mod && n)) {
            return true;
        }
    }
}

void build_truncatable_primes(int start) {
    if (!is_prime(start)) {
        return;
    }
    if (is_left_truncatable(start)) {
        std::cout << start << "\n";
    }
    build_truncatable_primes(start * 10 + 1);
    build_truncatable_primes(start * 10 + 3);
    build_truncatable_primes(start * 10 + 7);
    build_truncatable_primes(start * 10 + 9);
}
