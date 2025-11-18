/**
 * @file ScavTrap.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("ScavTrap") {
    this->hp = 100;
    this->ep = 50;
    this->atk = 20;
    showName();
    std::cout << "default ctor" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    this->hp = 100;
    this->ep = 50;
    this->atk = 20;
    showName();
    std::cout << "name ctor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
    this->hp = 100;
    this->ep = 50;
    this->atk = 20;
    showName();
    std::cout << "copy ctor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->hp = 100;
        this->ep = 50;
        this->atk = 20;
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    showName();
    std::cout << "dtor" << std::endl;
}

void ScavTrap::guardGate() {
    showName();
    std::cout << "Gate Keeper mode ON." << std::endl;
}

void ScavTrap::showName() const {
    std::cout << "ScavTrap [" << this->getName() << "]: ";
}