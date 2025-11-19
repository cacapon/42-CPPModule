/**
 * @file FlagTrap.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "FlagTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

FlagTrap::FlagTrap() : ClapTrap() {
    this->hp = HP;
    this->ep = EP;
    this->atk = ATK;
    showName();
    std::cout << "default ctor" << std::endl;
}

FlagTrap::FlagTrap(const std::string &name) : ClapTrap(name) {
    this->hp = HP;
    this->ep = EP;
    this->atk = ATK;
    showName();
    std::cout << "name ctor" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap &other) : ClapTrap(other) {
    this->hp = other.hp;
    this->ep = other.ep;
    this->atk = other.atk;
    showName();
    std::cout << "copy ctor" << std::endl;
}

FlagTrap &FlagTrap::operator=(const FlagTrap &other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->hp = other.hp;
        this->ep = other.ep;
        this->atk = other.atk;
    }
    return *this;
}

FlagTrap::~FlagTrap(){
    showName(); 
    std::cout << "dtor" << std::endl;
}

void FlagTrap::highFivesGuys() {
    if (this->hp == 0) {
        showName();
        std::cout << "highFivesGuys NG: hp=0" << std::endl;
        return;
    }
    showName();
    std::cout << "highFivesGuys OK: Request a high-five" << std::endl;
}

void FlagTrap::showName() const {
    std::cout << "FlagTrap [" << this->getName() << "]: ";
}