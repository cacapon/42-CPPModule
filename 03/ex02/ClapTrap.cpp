/**
 * @file ClapTrap.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief To me, it looks like nothing but a crocodile.
 *
 *
 */

#include "ClapTrap.hpp"

#include <iostream>
#include <string>

const std::string ClapTrap::DEFAULT_NAME = "???";
const unsigned int BASE_HP = 10;
const unsigned int BASE_EP = 10;
const unsigned int BASE_ATK = 0;

ClapTrap::ClapTrap()
    : name(DEFAULT_NAME), hp(BASE_HP), ep(BASE_EP), atk(BASE_ATK) {
    showName();
    std::cout << "default ctor" << std::endl;
}
ClapTrap::ClapTrap(const std::string& name)
    : name(name), hp(BASE_HP), ep(BASE_EP), atk(BASE_ATK) {
    showName();
    std::cout << "name ctor" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), hp(other.hp), ep(other.ep), atk(other.atk) {
    showName();
    std::cout << "copy ctor" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->name = other.name;
        this->hp = other.hp;
        this->ep = other.ep;
        this->atk = other.atk;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    showName();
    std::cout << "dtor" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->ep == 0) {
        showName();
        std::cout << "attack NG: ep=0" << std::endl;
        return;
    }
    if (this->hp == 0) {
        showName();
        std::cout << "attack NG: hp=0" << std::endl;
        return;
    }
    this->ep--;
    showName();
    std::cout << "attack OK: " << target << " <=(" << this->atk << ")"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hp == 0) {
        showName();
        std::cout << "takeDamage NG: hp=0" << std::endl;
        return;
    }
    showName();
    std::cout << "takeDamage OK: " << amount << " points of damage!"
              << std::endl;
    this->hp = this->hp <= amount ? 0 : this->hp - amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->ep == 0) {
        showName();
        std::cout << "beRepaired NG: ep=0" << std::endl;
        return;
    }
    if (this->hp == 0) {
        showName();
        std::cout << "beRepaired NG: hp=0" << std::endl;
        return;
    }
    this->ep--;
    showName();
    std::cout << "beRepaired OK: recovered " << amount << " points."
              << std::endl;
    this->hp += amount;
}

const std::string& ClapTrap::getName() const { return this->name; }
unsigned int ClapTrap::getHp() const { return this->hp; }
unsigned int ClapTrap::getEp() const { return this->ep; }
unsigned int ClapTrap::getAtk() const { return this->atk; }

void ClapTrap::showName() const {
    std::cout << "ClapTrap [" << this->name << "]: ";
}