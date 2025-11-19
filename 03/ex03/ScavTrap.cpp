/**
 * @file ScavTrap.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    this->hp = HP;
    this->ep = EP;
    this->atk = ATK;
    showName();
    std::cout << "default ctor" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hp = HP;
    this->ep = EP;
    this->atk = ATK;
    showName();
    std::cout << "name ctor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    this->hp = other.hp;
    this->ep = other.ep;
    this->atk = other.atk;
    showName();
    std::cout << "copy ctor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->hp = other.hp;
        this->ep = other.ep;
        this->atk = other.atk;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    showName();
    std::cout << "dtor" << std::endl;
}

void ScavTrap::guardGate() {
    if (this->hp == 0) {
        showName();
        std::cout << "guardGate NG: hp=0" << std::endl;
        return;
    }
    showName();
    std::cout << "Gate Keeper mode ON." << std::endl;
}

void ScavTrap::showName() const {
    std::cout << "ScavTrap [" << this->getName() << "]: ";
}