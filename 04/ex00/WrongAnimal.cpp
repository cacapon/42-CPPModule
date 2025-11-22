/**
 * @file WrongAnimal.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal::default ctor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
    this->type = other.type;
    std::cout << "WrongAnimal::copy ctor" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << "WrongAnimal::dtor" << std::endl; }

std::string WrongAnimal::getType() const { return this->type; }

void WrongAnimal::makeSound() const {
    std::cout << "This voice is not an animal's voice." << std::endl;
}