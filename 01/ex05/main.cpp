/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief That bacon Cramer has come.
 * 
 * 
 */

#include "Harl.hpp"
#include <iostream>

int main(void)
{
    Harl*   harl = new Harl();

    std::cout << std::endl;
    harl->complain("DEBUG");
    std::cout << std::endl;
    harl->complain("INFO");
    std::cout << std::endl;
    harl->complain("WARNING");
    std::cout << std::endl;
    harl->complain("ERROR");
    std::cout << std::endl;
    harl->complain("ELSE");
    std::cout << std::endl;
    delete harl;
    return (0);
}