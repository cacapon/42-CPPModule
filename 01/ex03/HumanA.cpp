/**
 * @file HumanA.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
    : name(name), my_weapon(weapon) {}

HumanA::~HumanA() {
  std::cout << this->name << " laid down his " << this->my_weapon.getType()
            << " and left the battlefield.\n";
}

void HumanA::attack(void) {
  std::cout << this->name << " attacks with their " << this->my_weapon.getType()
            << "\n";
}
