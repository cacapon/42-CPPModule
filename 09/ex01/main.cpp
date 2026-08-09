/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-08
 *
 *
 */

#include <iostream>

#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) return 1;
    RPN rpn = RPN();
    try {
        std::cout << rpn.expr(av[1]) << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
