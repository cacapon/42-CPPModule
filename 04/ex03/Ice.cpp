/**
 * @file Ice.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Ice.hpp"

#include <iostream>

#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") { ShowLog("Ice", "default ctor"); }

Ice::Ice(const Ice &other) : AMateria(other) { ShowLog("Ice", "copy ctor"); }

Ice &Ice::operator=(const Ice &other) {
    ShowLog("Ice", "operator=");
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Ice::~Ice() { ShowLog("Ice", "dtor"); }

AMateria *Ice::clone() const {
    ShowLog("Ice", "clone");
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}