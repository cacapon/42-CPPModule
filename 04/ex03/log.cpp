/**
 * @file log.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "log.hpp"

#include <iostream>

void ShowLog(const std::string &cls, const std::string &detail) {
#ifdef DEBUG
    std::cout << cls << "::" << detail << std::endl;
#else
    (void)cls;
    (void)detail;
#endif
}