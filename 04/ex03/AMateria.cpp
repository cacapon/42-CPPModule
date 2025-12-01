/**
 * @file AMateria.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "AMateria.hpp"

#include <iostream>

static void ShowLog(const std::string detail) {
    std::cout << "AMateria::" << detail << std::endl;
}

AMateria::AMateria() { ShowLog("default ctor"); }

AMateria::AMateria(std::string const &type) : type(type) {
    ShowLog("name ctor");
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
    ShowLog("copy ctor");
}

AMateria &AMateria::operator=(const AMateria &other) {
    ShowLog("operator=");
    if (this != &other) this->type = other.getType();
    return *this;
}

AMateria::~AMateria() { ShowLog("dtor"); }

std::string const &AMateria::getType() const { return this->type; };

void AMateria::use(ICharacter &target) {
    (void)target;
    ShowLog("use::not working.");
}
