/**
 * @file Harl.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief Bacon-loving complainer
 * 
 * 
 */

#include "Harl.hpp"

Harl::Harl(void)
{
    std::cout << "Since he's here, we'll need to keep an eye on the bacon supply." << std::endl;
}
Harl::~Harl(void)
{
    std::cout << "He's gone. He ate all the bacon in the store." << std::endl;
}


void    Harl::complain(std::string level)
{
    switch (getCmd(level))
    {
    case 0:
        debug();
        break;
    case 1:
        info();
        break;
    case 2:
        warning();
        break;
    case 3:
        error();
        break;
    default:
        default_msg();
        break;
    }
}

int   Harl::getCmd(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i=0; i<4; i++)
        if (levels[i] == level)
            return (i);
    return (-1);
}

void    Harl::debug(void)
{
    std::cout 
        << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl
        << "I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout
        << "I cannot believe adding extra bacon costs more money." << std::endl
        << "You didn’t put enough bacon in my burger!" << std::endl
        << "If you did, I wouldn’t be asking for more!" << std::endl;
}
void    Harl::warning(void)
{
    std::cout 
        << "I think I deserve to have some extra bacon for free." << std::endl
        << "I’ve been coming for years, whereas you started working here just last month."  << std::endl;
}
void    Harl::error(void)
{
    std::cout 
        << "This is unacceptable!"  << std::endl
        << "I want to speak to the manager now."  << std::endl;
}
void    Harl::default_msg(void)
{
    std::cout << "Probably complaining about insignificant problems..." << std::endl;
}
