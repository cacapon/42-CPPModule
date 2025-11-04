/**
 * @file newZombie.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    return new Zombie(name);
}