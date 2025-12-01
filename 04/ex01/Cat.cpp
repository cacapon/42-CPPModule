/**
 * @file Cat.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Cat.hpp"

#include <iostream>

Cat::Cat() : Animal(), brain() {
    this->type = "Cat";
    std::cout << "Cat::default ctor" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), brain(other.brain) {
    std::cout << "Cat::copy ctor" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        this->brain = other.brain;
    }
    std::cout << "Cat::operator=" << std::endl;
    return *this;
}

Cat::~Cat() { std::cout << "Cat::dtor" << std::endl; }

void Cat::makeSound() const { std::cout << "Meow" << std::endl; }