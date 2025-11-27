/**
 * @file Cure.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Cure.hpp"

#include <iostream>

#include "ICharacter.hpp"

static void ShowLog(const std::string detail) {
    std::cout << "Cure::" << detail << std::endl;
}

Cure::Cure() : AMateria("cure") { ShowLog("default ctor"); }

Cure::Cure(const Cure &other) : AMateria(other) { ShowLog("copy ctor"); }

Cure &Cure::operator=(const Cure &other) {
    ShowLog("operator=");
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Cure::~Cure() { ShowLog("dtor"); }

AMateria *Cure::clone() const {
    ShowLog("clone");
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}