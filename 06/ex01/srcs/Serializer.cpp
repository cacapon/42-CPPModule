/**
 * @file Serializer.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Serializer.hpp"

#include <iostream>
#include <string>

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "Serializer::" << detail << std::endl;
#else
    (void)detail;
#endif
}

/* public methods */
uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

/* canonical form - private because instantiation is not allowed */
Serializer::Serializer() { ShowLog("Err:default ctor"); }

Serializer::Serializer(const Serializer& other) {
    (void)other;
    ShowLog("Err:copy ctor");
}

Serializer& Serializer::operator=(const Serializer& other) {
    (void)other;
    ShowLog("Err:operator=");
    return *this;
}

Serializer::~Serializer() { ShowLog("Err:dtor"); }
