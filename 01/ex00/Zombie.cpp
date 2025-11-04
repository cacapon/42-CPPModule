/**
 * @file Zombie.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#include <iostream>
#include "Zombie.hpp"


Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " has returned to the earth\n";
}


void Zombie::announce(void)
{
	std::cout << this->name << ":BraiiiiiiinnnzzzZ...\n";
}