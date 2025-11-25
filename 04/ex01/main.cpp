/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main() {
    const int MAX = 10;
    Animal *animals[MAX];
    std::cout << "<<<instantiate>>>" << std::endl;
    for (int i = 0; i < MAX; i += 2) {
        animals[i] = new Dog();
        animals[i + 1] = new Cat();
    }
    std::cout << "<<<makeSound>>>" << std::endl;
    for (int i = 0; i < MAX; i++) {
        std::cout << animals[i]->getType() << ":";
        animals[i]->makeSound();
    }
    std::cout << "<<<delete>>>" << std::endl;
    for (int i = 0; i < MAX; i++) delete animals[i];
    return 0;
}