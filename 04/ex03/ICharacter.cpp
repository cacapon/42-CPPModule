/**
 * @file ICharacter.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ICharacter.hpp"

#include <iostream>

static void ShowLog(const std::string detail) {
    std::cout << "ICharacter::" << detail << std::endl;
}

ICharacter::~ICharacter() { ShowLog("dtor"); }
