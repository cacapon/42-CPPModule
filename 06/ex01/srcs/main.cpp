/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <stdint.h>

#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data d;
    d.value = 42;
    uintptr_t ptr = Serializer::serialize(&d);
    Data *p = Serializer::deserialize(ptr);
    std::cout << "Data:" << d.value << std::endl;
    std::cout << "ptr:" << p->value << std::endl;

    return 0;
}