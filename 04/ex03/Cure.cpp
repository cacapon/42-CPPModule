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

Cure::Cure() : AMateria("cure") { ShowLog("Cure", "default ctor"); }

Cure::Cure(const Cure &other) : AMateria(other) {
    ShowLog("Cure", "copy ctor");
}

Cure &Cure::operator=(const Cure &other) {
    ShowLog("Cure", "operator=");
    if (this != &other) AMateria::operator=(other);
    return *this;
}

Cure::~Cure() { ShowLog("Cure", "dtor"); }

AMateria *Cure::clone() const {
    ShowLog("Cure", "clone");
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}