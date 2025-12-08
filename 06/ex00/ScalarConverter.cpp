/**
 * @file ScalarConverter.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

using std::atoi;

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "ScalarConverter::" << detail << std::endl;
#else
    (void)detail;
#endif
}

void ScalarConverter::convert(const std::string &str) {
    fromChar(str);
    fromInt(str);
    fromFloat(str);
    fromDouble(str);
}

ScalarConverter::ScalarConverter() { ShowLog("Err:default ctor"); }

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
    ShowLog("Err:copy ctor");
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    ShowLog("Err:operator=");
    return *this;
}

ScalarConverter::~ScalarConverter() { ShowLog("Err:dtor"); }

bool ScalarConverter::isChar(const std::string &str) {
    if (str.length() != 1) return false;
    unsigned char c = static_cast<unsigned char>(str[0]);
    if (c > 127) return false;
    return true;
}

bool ScalarConverter::isInt(const std::string &str) {
    size_t i = 0;
    int digitCount;

    if (str.empty()) return false;
    if (str.length() == 1 && !std::isdigit(str[i])) return false;
    if (str[i] == '+' || str[i] == '-') i++;

    for (; i < str.length(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    digitCount =
        (str[0] == '+' || str[0] == '-') ? (str.length() - 1) : str.length();
    if (digitCount > 10) return false;
    if (digitCount == 10) {
        if (str[0] == '-' && str.compare("-2147483648") > 0)
            return false;
        else if (str.compare("+2147483648") > 0 &&
                 str.compare("2147483648") > 0)
            return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &str) {
    (void)str;
    return false;
}
bool ScalarConverter::isDouble(const std::string &str) {
    (void)str;
    return false;
}

void ScalarConverter::fromChar(const std::string str) {
    std::cout << "char: ";
    if (!isChar(str))
        std::cout << "impossible";
    else if (!std::isprint(str[0]))
        std::cout << "Non displayable";
    else
        std::cout << "'" << str[0] << "'";
    std::cout << std::endl;
}

void ScalarConverter::fromInt(const std::string str) {
    // TODO
    std::cout << "int: ";
    if (!isInt(str))
        std::cout << "impossible";
    else
        std::cout << std::atoi(str.c_str());
    std::cout << std::endl;
}
void ScalarConverter::fromFloat(const std::string str) {
    // TODO
    (void)str;
}
void ScalarConverter::fromDouble(const std::string str) {
    // TODO
    (void)str;
}