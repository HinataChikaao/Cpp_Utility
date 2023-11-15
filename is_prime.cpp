#include <iostream>
#include <cmath>

bool is_prime(const long long unsigned int number);

int main() {

    for (long long unsigned int number = 3; number < 10'000'000; number += 2) {
        if (is_prime(number)) {
            std::cout << number << "\t";
        }
    }

    std::cout << "\nThe End ..." << std::endl;
    return EXIT_SUCCESS;
}

bool is_prime(const long long unsigned int number) {
    if (number == 1 || number == 2) return true;
    if (number == 0) return false;
    if (number % 2 == 0) return false;
    bool result{true};
    size_t sqr{static_cast<size_t>(sqrt(static_cast<double>(number))) + 1};
    for (size_t i = 3; i < sqr; i += 2) {
        if (number % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}