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

static void ShowLog(const std::string detail) {
    std::cout << "Ice::" << detail << std::endl;
}

Ice::Ice() : AMateria("ice") { ShowLog("default ctor"); }

Ice::Ice(const Ice &other) : AMateria(other) { ShowLog("copy ctor"); }

Ice &Ice::operator=(const Ice &other) {
    ShowLog("operator=");
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Ice::~Ice() { ShowLog("dtor"); }

AMateria *Ice::clone() const {
    ShowLog("clone");
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"
              << std::endl;
}