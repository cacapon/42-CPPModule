/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // 猫の鳴き声を出力します！
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    return 0;
}