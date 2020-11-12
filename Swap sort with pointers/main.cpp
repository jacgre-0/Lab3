#include <iostream>

void swap_sort_ptr(int* a, int* b, int* c, bool sortOrder);

int main() {
    int a{};
    int b{};
    int c{};
    bool sortOrder{};

    std::cout << "Give a (0 to quit): ";
    std::cin >> a;
    if (a == 0) {
        std::cout << "Bye bye!";
        return 0;
    }

    std::cout << "Give b: ";
    std::cin >> b;

    std::cout << "Give c: ";
    std::cin >> c;

    std::cout << "Sort ascending/descending (1/0): ";
    std::cin >> sortOrder;

    swap_sort_ptr(&a, &b, &c, sortOrder);

    std::cout << "Result: " << a << ", " << b << ", " << c << std::endl;
    return 0;
}

void swap_sort_ptr(int* a, int* b, int* c, bool sortOrder) {
    //sort ascending
    {
        bool worstCaseFlag{ false };

        if (*a > *b) {
            int temp = *a;
            *a = *b;
            *b = temp;
        }

        if (*b > *c) {
            //If b is greater than c, we need to compare and possibly swap a and b again 
            //(since b is now c and we haven't compared a with c)
            //So we set the flag to true
            worstCaseFlag = true;

            int temp = *b;
            *b = *c;
            *c = temp;
        }

        if (worstCaseFlag) {
            if (*a > *b) {
                int temp = *a;
                *a = *b;
                *b = temp;
            }
        }
    }

    //sort descending
    //Just reverse the order by swapping a and c
    if (!sortOrder) {
        int temp = *a;
        *a = *c;
        *c = temp;
    }
}