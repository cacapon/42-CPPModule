/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
#include "OpenIOFile.hpp"
#include "ReplaceAll.hpp"

/**
 * @brief Outputs usage.
 * 
 */
void    print_usage()
{
    std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
}

/**
 * @brief Reads each line from input, performs replacements, and outputs the result to output.
 * 
 * @param input 
 * @param output 
 * @param s1 
 * @param s2 
 */
void    process(
    std::ifstream       &input, 
    std::ostream        &output,
    const std::string   s1,
    const std::string   s2
)
{
    std::string line;

    while(std::getline(input, line))
        output << replace_all(line, s1, s2) << std::endl;
}

#ifndef TEST_MODE
int main(int ac, char **av)
{
    std::ifstream   input;
    std::ofstream   output;

    if (ac != 4)
        return (print_usage(), 1);
    if (!open_input(input, av[1]))
        return (1);
    if (!open_output(output, av[1]))
        return (1);
    process(input, output, av[2], av[3]);
    input.close();
    output.close();
    return (0);
}
#endif

#ifdef TEST_MODE
#include <stdlib.h>
int main(void)
{
    std::ofstream test_in("test_in.txt");
    test_in << "apple orange banana apple";
    test_in.close();

    system("./SedIsForLosers test_in.txt apple grape");

    std::ifstream result("test_in.txt.replace");
    std::string content;
    std::string expected = "grape orange banana grape";
    std::getline(result, content);
    result.close();

    if (content == expected)
        std::cout << "OK: Test passed!" << std::endl;
    else
    {
        std::cout << "NG: Test failed."       << std::endl;
        std::cout << "Expected: " << expected << std::endl;
        std::cout << "Got:      " << content  << std::endl;
    }
    return (0);
}
#endif