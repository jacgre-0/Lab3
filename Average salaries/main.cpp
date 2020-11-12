#include <iostream>

float average_salary(const int* salaries, int length);

int main() {
    int size{};
    int salary{};
    int* salaryArray = nullptr;

    std::cout << "Give total number of employees: ";
    std::cin >> size;

    salaryArray = new int[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Give salary: ";
        std::cin >> salaryArray[i];
    }

    std::cout << average_salary(salaryArray, size);

    delete[] salaryArray;
    return 0;
}

float average_salary(const int* salaries, int length) {
    int total{};

    for (int i = 0; i < length; i++) {
        total += *salaries++;
    }
    return static_cast<float>(total) / length;
}