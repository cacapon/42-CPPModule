/**
 * @file HumanB.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name) { this->my_weapon = NULL; }

HumanB::~HumanB() {
  if (!this->my_weapon) {
    std::cout << this->name << " left the battlefield.\n";
  } else {
    std::cout << this->name << " laid down his" << this->my_weapon->getType()
              << " and left the battlefield.\n";
  }
}

void HumanB::attack(void) {
  if (!this->my_weapon) {
    std::cout << this->name << " attacks with his fists.\n";
  } else {
    std::cout << this->name << " attacks with their "
              << this->my_weapon->getType() << "\n";
  }
}
void HumanB::setWeapon(Weapon &weapon) { this->my_weapon = &weapon; }
