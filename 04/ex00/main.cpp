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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void test_copy_ctor_animal() {
    std::cout << "===Animal::copy ctor test===" << std::endl;
    Animal a;
    Animal b(a);

    std::cout << b.getType() << std::endl;
    b.makeSound();
}

static void test_assign_animal() {
    std::cout << "===Animal::operator= test===" << std::endl;
    Animal a;
    Animal b;
    b = a;

    std::cout << b.getType() << std::endl;
    b.makeSound();
}

static void test_copy_ctor_dog() {
    std::cout << "===Dog::copy ctor test===" << std::endl;
    Dog a;
    Dog b(a);

    std::cout << b.getType() << std::endl;
    b.makeSound();
}

static void test_assign_dog() {
    std::cout << "===Dog::operator= test===" << std::endl;
    Dog a;
    Dog b;
    b = a;

    std::cout << b.getType() << std::endl;
    b.makeSound();
}

static void test_copy_ctor_cat() {
    std::cout << "===Cat::copy ctor test===" << std::endl;
    Cat a;
    Cat b(a);

    std::cout << b.getType() << std::endl;
    b.makeSound();
}

static void test_assign_cat() {
    std::cout << "===Cat::operator= test===" << std::endl;
    Cat a;
    Cat b;
    b = a;

    std::cout << b.getType() << std::endl;
    b.makeSound();
}

static void test_ft_subject() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "===42 Subject basic test===" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
}

static void test_wrong_animal() {
    const WrongAnimal* wa = new WrongCat();

    std::cout << "===Wrong animal test===" << std::endl;
    std::cout << wa->getType() << " " << std::endl;
    wa->makeSound();
    delete wa;
}

int main() {
    test_copy_ctor_animal();
    test_assign_animal();
    test_copy_ctor_dog();
    test_assign_dog();
    test_copy_ctor_cat();
    test_assign_cat();
    test_ft_subject();
    test_wrong_animal();
}