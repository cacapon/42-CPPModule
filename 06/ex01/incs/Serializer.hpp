/**
 * @file Serializer.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include "Data.hpp"

class Serializer {
   public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

   private:
    /* canonical form - private because instantiation is not allowed */
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
};

#endif