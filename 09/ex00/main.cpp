/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-07
 *
 *
 */

#include <exception>
#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cout << "usage: ./btc <inputfile>";
        return 1;
    }
    try {
        BitcoinExchange btc("data.csv");
        std::string path(av[1]);
        btc.loadInputText(path);
    } catch (std::exception &e) {
        std::cerr << "[Exception caught]" << e.what() << std::endl;
    }
    return 0;
}
