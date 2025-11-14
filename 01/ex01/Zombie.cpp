/**
 * @file Zombie.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

Zombie::~Zombie(void) {
  std::cout << this->name << " has returned to the earth\n";
}

void Zombie::setName(std::string name) { this->name = name; }

void Zombie::announce(void) {
  std::cout << this->name << ":BraiiiiiiinnnzzzZ...\n";
}