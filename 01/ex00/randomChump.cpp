/**
 * @file randomChump.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#include "Zombie.hpp"

void randomChump(std::string name)
{
    Zombie zombie = Zombie(name);
    zombie.announce();
}
