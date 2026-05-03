/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>

#include "iter.hpp"

/* helper functions */
template <typename T>
void print(const T& x) {
    std::cout << x;
}

void increment_char(char& c) { c++; }

/* main */
int main() {
    int a[] = {1, 2, 3};
    const int b[] = {4, 5, 6};
    char c[] = {'a', 'b', 'c', 'd'};

    ::iter(a, 3, print);
    std::cout << std::endl;
    ::iter(b, 3, print);
    std::cout << std::endl;
    ::iter(c, 4, increment_char);
    ::iter(c, 4, print);
    std::cout << std::endl;
    return 0;
}