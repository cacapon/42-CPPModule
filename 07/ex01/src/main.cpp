/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>

#include "Iter.hpp"

void print_x(int &x) { std::cout << x << std::endl; }
void print_const_x(const int &x) { std::cout << x << std::endl; }
void increment_char(char &c) { c++; }

int main() {
    int a[] = {1, 2, 3};
    const int b[] = {4, 5, 6};
    char c[] = {'a', 'b', 'c', 'd'};

    ::iter(a, 3, print_x);
    std::cout << std::endl;
    ::iter(b, 3, print_const_x);
    std::cout << std::endl;
    ::iter(c, 4, increment_char);
    for (size_t i = 0; i < 4; i++) std::cout << c[i];
    std::cout << std::endl;
    return 0;
}