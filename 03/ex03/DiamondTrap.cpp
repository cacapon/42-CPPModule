/**
 * @file DiamondTrap.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap()
    : ScavTrap(ClapTrap::DEFAULT_NAME + "_clap_name"),
      FragTrap(ClapTrap::DEFAULT_NAME + "_clap_name"), name() {
    this->FragTrap::hp = FragTrap::HP;
    this->ScavTrap::ep = ScavTrap::EP;
    this->FragTrap::atk = FragTrap::ATK;
    showName();
    std::cout << "default ctor" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), name(name) {
    this->FragTrap::hp = FragTrap::HP;
    this->ScavTrap::ep = ScavTrap::EP;
    this->FragTrap::atk = FragTrap::ATK;
    showName();
    std::cout << "name ctor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ScavTrap(other), FragTrap(other) {
    this->FragTrap::hp = other.FragTrap::hp;
    this->ScavTrap::ep = other.ScavTrap::ep;
    this->FragTrap::atk = other.FragTrap::atk;
    showName();
    std::cout << "copy ctor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
    if (this != &other) {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    showName();
    std::cout << "dtor" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "whoAmI:"
              << "ClapTrapName:[" << this->ScavTrap::name << "]\t"
              << "DiamondTrapName:[" << this->name << "]" << std::endl;
}

void DiamondTrap::showName() const {
    std::cout << "DiamondTrap [" << this->name << "]: ";
}