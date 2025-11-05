/**
 * @file Weapon.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief What an incredible weapon this is!
 * 
 * 
 */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::~Weapon()
{
    std::cout << this->type << " is no longer usable.\n";
}

std::string Weapon::getType(void)
{
    return this->type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}