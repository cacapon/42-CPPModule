/**
 * @file FragTrap.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    this->hp = HP;
    this->ep = EP;
    this->atk = ATK;
    showName();
    std::cout << "default ctor" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    this->hp = HP;
    this->ep = EP;
    this->atk = ATK;
    showName();
    std::cout << "name ctor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
    this->hp = other.hp;
    this->ep = other.ep;
    this->atk = other.atk;
    showName();
    std::cout << "copy ctor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->hp = other.hp;
        this->ep = other.ep;
        this->atk = other.atk;
    }
    return *this;
}

FragTrap::~FragTrap() {
    showName();
    std::cout << "dtor" << std::endl;
}

void FragTrap::highFivesGuys() {
    if (this->hp == 0) {
        showName();
        std::cout << "highFivesGuys NG: hp=0" << std::endl;
        return;
    }
    showName();
    std::cout << "highFivesGuys OK: Request a high-five" << std::endl;
}

void FragTrap::showName() const {
    std::cout << "FragTrap [" << this->getName() << "]: ";
}