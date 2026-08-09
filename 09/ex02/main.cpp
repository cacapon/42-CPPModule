/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-09
 *
 *
 */

#include <exception>
#include <iostream>

#include "PmergeMe.hpp"

int main(int ac, char** av) {
    PmergeMe ins;
    try {
        ins.run(ac, av);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
