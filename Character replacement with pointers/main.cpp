#include <iostream>

void replace_chars(char* str, char searhChar, char replacementChar);

int main() {
    char str[] = "Hello";
    replace_chars(str, 'l', 'p');
    replace_chars(str, 'H', 'l');
    std::cout << str << std::endl;
    return 0;
}

void replace_chars(char* str, char searhChar, char replacementChar) {
    while (*str != '\0') {
        if (*str == searhChar) {
            *str = replacementChar;
        }
        str++;
    }
}