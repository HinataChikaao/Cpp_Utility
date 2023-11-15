/* A Thousand Separator Function */

#include <iostream>
#include <cmath>

std::string thousand_separator(std::string number, size_t group, char delim);

std::string thousand_separator(long long int number, size_t group, char delim);

bool thousand_separator_test(const std::string &number, size_t group, char delim);

int main() {

    std::string number{};
    //size_t number{};

    const char delim = ',';

    for (size_t group = 1; group < 1000; group++) {

        number = "1";
        //number = 1;

        for (size_t i = 0; i < 1000; i++) {

            number.append(std::to_string(i));
            //number *= 10;

            std::string result = thousand_separator(number, group, delim);
            //std::string result = thousand_separator(static_cast<long long int>(number), group, delim);

            if (!thousand_separator_test(result, group, delim)) {
                std::cerr << "main: ---------------------------------------------------" << std::endl;
                std::cerr << "error: " << std::endl;
                std::cerr << "group: " << group << std::endl;
                std::cerr << "number: " << number << std::endl;
                std::cerr << "length number: " << number.length() << std::endl;
                std::cerr << "result: " << result << std::endl;
                std::cerr << "main: ---------------------------------------------------" << std::endl;
                exit(EXIT_FAILURE);
            }

        }
    }

    std::cout << "\nThe End ..." << std::endl;
    return EXIT_SUCCESS;
}

std::string thousand_separator(std::string number = "0", const size_t group = 3, const char delim = ',') {

    const size_t zero = 0;
    const size_t one = 1;

    size_t length = number.length();
    if (length < group) return number;
    size_t first_comma = length % group;

    if (first_comma > zero) {
        number.insert(number.begin() + static_cast<long long int>(first_comma), delim);
        first_comma++;
    }

    length += (length / group) - one;
    for (size_t i = group + first_comma; i < length; i += (group + one)) {
        number.insert(number.begin() + static_cast<long long int>(i), delim);
    }
    return number;
}

std::string thousand_separator(long long int number = 0, const size_t group = 3, const char delim = ',') {

    const size_t zero = 0;
    const size_t one = 1;

    std::string str_number = std::to_string(number);

    size_t length = str_number.length();
    if (length < group) return str_number;
    size_t first_comma = length % group;

    if (first_comma > zero) {
        str_number.insert(str_number.begin() + static_cast<long long int>(first_comma), delim);
        first_comma++;
    }

    length += (length / group) - one;
    for (size_t i = group + first_comma; i < length; i += (group + one)) {
        str_number.insert(str_number.begin() + static_cast<long long int>(i), delim);
    }
    return str_number;
}

bool thousand_separator_test(const std::string &number = "0", const size_t group = 3, const char delim = ',') {

    size_t digit_number{};
    for (char iter: number) {
        if (isdigit(iter)) {
            digit_number++;
        }
    }

    if (digit_number < group) return true;

    size_t comma_number = 0;
    for (const char &item: number) {
        if (item == delim) comma_number++;
    }

    size_t check_comma_number = digit_number / group;

    if (digit_number % group == 0) {
        check_comma_number--;
    }

    size_t last_comma = number.find_last_of(',');

    bool c1 = (comma_number == check_comma_number);
    bool c2 = (number[0] != delim);
    bool c3 = group == ((digit_number + comma_number - 1) - last_comma);

    bool test_result = c1 && c2 && c3;


    if (!test_result) {

        std::cerr << "test: ---------------------------------------------------" << std::endl;

        if (!c1) {
            std::cerr << "check one has problem" << std::endl;
        } else if (!c2) {
            std::cerr << "check two has problem" << std::endl;
        } else if (!c3) {
            std::cerr << "check three has problem" << std::endl;
            std::cerr << "calculate: " << (last_comma - (digit_number + comma_number - 1)) << std::endl;
        }

        std::cerr << "digit No: " << digit_number << std::endl;
        std::cerr << "comma No: " << comma_number << std::endl;
        std::cerr << "last comma position: " << last_comma << std::endl;
        std::cerr << "group No: " << group << std::endl;
        std::cerr << "check comma No: " << check_comma_number << std::endl;
        std::cerr << "test: ---------------------------------------------------" << std::endl;
    }

    return test_result;
}
