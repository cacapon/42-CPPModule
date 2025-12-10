/**
 * @file Base.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Base.hpp"

#include <iostream>
#include <string>

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "Base::" << detail << std::endl;
#else
    (void)detail;
#endif
}

Base::~Base() { ShowLog("dtor"); }
