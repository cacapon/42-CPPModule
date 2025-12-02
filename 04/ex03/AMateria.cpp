/**
 * @file AMateria.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria() { ShowLog("Amateria", "default ctor"); }

AMateria::AMateria(std::string const &type) : type(type) {
    ShowLog("Amateria", "name ctor");
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
    ShowLog("Amateria", "copy ctor");
}

AMateria &AMateria::operator=(const AMateria &other) {
    ShowLog("Amateria", "operator=");
    if (this != &other) this->type = other.getType();
    return *this;
}

AMateria::~AMateria() { ShowLog("Amateria", "dtor"); }

std::string const &AMateria::getType() const { return this->type; };

void AMateria::use(ICharacter &target) {
    (void)target;
    ShowLog("Amateria", "use::not working.");
}
