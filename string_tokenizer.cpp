#include <cstring>
#include <iostream>
#include <string>

char *string_tokenizer(const char *input_str, const char *tokens);

int main() {

    std::string msg{"I am a C/C++ Developer ..."};

    char *buff = string_tokenizer(msg.c_str(), "");

    std::cout << "--------------------------" << '\n';
    std::cout << buff << '\n';
    for (char *c = buff; *c; c++) {
        std::cout << *c << '\n';
    }
    std::cout << "--------------------------" << '\n';

    std::cout << "\nThe End ..." << std::endl;
    return EXIT_SUCCESS;
}

char *string_tokenizer(const char *input_str = "", const char *tokens = "") {

    size_t counter{};
    bool accept{};

    char *buff = static_cast<char *>(calloc(strlen(input_str), sizeof(char)));

    memset(buff, '\0', strlen(buff));

    for (const char *in_str = input_str; *in_str; in_str++) {

        accept = true;

        for (const char *c = tokens; *c; c++) {

            if (*in_str == *c) {
                accept = false;
                break;
            }
        }

        if (accept) {
            buff[counter++] = *in_str;
        }
    }
    return buff;
}