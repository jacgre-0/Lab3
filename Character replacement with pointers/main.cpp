#include <iostream>

void replace_chars(char* str, char searhChar, char replacementChar);

int main() {
    char str[] = "Hello";
    std::cout << str << std::endl;
    replace_chars(str, 'l', 'h');
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