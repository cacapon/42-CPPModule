/**
 * @file main.c
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>

#include "ScalarConverter.hpp"

static void usage() {
    std::cout << "Usage: ./scalerConverter <num>" << std::endl;
}

int main(int argc, char **argv) {
    if (argc != 2) return (usage(), 1);
    ScalarConverter::convert(argv[1]);
    return (0);
}