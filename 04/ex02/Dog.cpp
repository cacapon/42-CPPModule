/**
 * @file Dog.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal(), brain() {
    this->type = "Dog";
    std::cout << "Dog::default ctor" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(other.brain) {
    std::cout << "Dog::copy ctor" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        this->brain = other.brain;
    }
    std::cout << "Dog::operator=" << std::endl;
    return *this;
}

Dog::~Dog() { std::cout << "Dog::dtor" << std::endl; }

void Dog::makeSound() const { std::cout << "Woof woof!" << std::endl; }