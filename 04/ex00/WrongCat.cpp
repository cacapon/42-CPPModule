/**
 * @file WrongCat.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << "WrongCat::default ctor" << std::endl;
}
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "WrongCat::copy ctor" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

WrongCat::~WrongCat() { std::cout << "WrongCat::dtor" << std::endl; }

void WrongCat::makeSound() const { std::cout << "Meow???" << std::endl; }