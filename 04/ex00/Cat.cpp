/**
 * @file Cat.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    this->type = "Cat";
    std::cout << "Cat::default ctor" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other) {
    if (this != &other) {
        this->type = other.type;
    }
    std::cout << "Cat::copy ctor" << std::endl;
}

Cat::~Cat() { std::cout << "Cat::dtor" << std::endl; }

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }