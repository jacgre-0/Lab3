#include <iostream>

int findLenghtOfString(char* str);

int main() {
    char arr[] = "";
    int length = findLenghtOfString(arr);

    std::cout << length << std::endl;
}

int findLenghtOfString(char* str) {
    for (int i = 0; ; i++) {
        if (*str++ == '\0') {
            return i;
        }
    }
}