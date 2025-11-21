/**
 * @file Animal.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Animal.hpp"
#include <iostream>
#include <string>

Animal::Animal() { std::cout << "Animal::default ctor" << std::endl; }

Animal::Animal(const Animal &other) {
    this->type = other.type;
    std::cout << "Animal::copy ctor" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() { std::cout << "Animal::dtor" << std::endl; }

std::string Animal::getType() const { return this->type; }

void Animal::makeSound() const {
    std::cout << "I hear animal sounds... What could they be?" << std::endl;
}