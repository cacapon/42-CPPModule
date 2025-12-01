/**
 * @file IMateriaSource.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "IMateriaSource.hpp"

#include <iostream>

static void ShowLog(const std::string detail) {
    std::cout << "IMateriaSource::" << detail << std::endl;
}

IMateriaSource::~IMateriaSource() { ShowLog("dtor"); }
