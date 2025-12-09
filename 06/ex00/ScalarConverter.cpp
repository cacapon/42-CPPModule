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

void ScalarConverter::convert(const std::string &s) {
    fromChar(s);
    fromInt(s);
    fromFloat(s);
    fromDouble(s);
}

/* canonical form - private because instantiation is not allowed */
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

/* Check whether the provided string can be converted to the type */
bool ScalarConverter::isChar(const std::string &s) {
    if (s.length() != 1) return false;
    unsigned char c = static_cast<unsigned char>(s[0]);
    if (c > 127) return false;
    return true;
}

bool ScalarConverter::isInt(const std::string &s) {
    if (regexInt(s))
        return fitsInInt(s);
    else if (regexFloat(s) || regexDouble(s)) {
        if (!decimalIsZero(s)) return false;
        return fitsInInt(extractIntegerPart(s));
    } else
        return false;
}

bool ScalarConverter::isFloat(const std::string &s) {
    (void)s;
    return false;
}
bool ScalarConverter::isDouble(const std::string &s) {
    (void)s;
    return false;
}

/* helper methods */
// pre: The string s that is passed is known to already consist of integers.
bool ScalarConverter::fitsInInt(const std::string &s) {
    size_t i = 0;
    if (s[0] == '+' || s[0] == '-') i++;
    while (i < s.length() && s[i] == '0') i++;
    int digitCount = s.length() - i;
    if (digitCount > 10) return false;
    if (digitCount == 10) {
        const std::string digits = s.substr(i);
        if (s[0] == '-' && digits.compare("2147483648") > 0)
            return false;
        else if (s[0] != '-' && digits.compare("2147483647") > 0)
            return false;
    }
    return true;
}

// ^[+-]?[0-9]+$
bool ScalarConverter::regexInt(const std::string &s) {
    size_t i = 0;
    if (s.empty()) return false;
    if (s[i] == '+' || s[i] == '-') i++;
    size_t start = i;
    while (i < s.length() && std::isdigit(s[i])) i++;
    if (start == i) return false;
    return i == s.length();
}

// ^[+-]?[0-9]+\.[0-9]+f$
bool ScalarConverter::regexFloat(const std::string &s) {
    size_t i = 0;
    if (s.empty()) return false;
    if (s[i] == '+' || s[i] == '-') i++;
    size_t startInt = i;
    while (i < s.length() && std::isdigit(s[i])) i++;
    if (i == startInt) return false;

    if (i >= s.length() || s[i] != '.') return false;
    i++;
    size_t startFrac = i;
    while (i < s.length() && std::isdigit(s[i])) i++;
    if (startFrac == i) return false;

    if (i != s.length() - 1) return false;
    if (s[s.length() - 1] != 'f') return false;
    return true;
}

// ^[+-]?[0-9]+(\.[0-9]+)?$
bool ScalarConverter::regexDouble(const std::string &s) {
    size_t i = 0;
    if (s.empty()) return false;
    if (s[i] == '+' || s[i] == '-') i++;
    while (i < s.length() && std::isdigit(s[i])) i++;
    if (i < s.length() && s[i] == '.') {
        i++;
        size_t startFrac = i;
        while (i < s.length() && std::isdigit(s[i])) i++;
        if (i == startFrac) return false;
    }
    return i == s.length();
}

// Check whether the digit after the decimal point is zero.
bool ScalarConverter::decimalIsZero(const std::string &s) {
    size_t pos = s.find('.');
    if (pos == std::string::npos) return true;
    pos++;
    while (pos < s.length() && s[pos] == '0') pos++;
    size_t lastDigit = (s[s.length() - 1] == 'f') ? s.length() - 1 : s.length();
    return pos == lastDigit;
}

std::string ScalarConverter::extractIntegerPart(const std::string &s) {
    size_t pos = s.find('.');
    if (pos == std::string::npos) return s;
    return s.substr(0, pos);
}

/* Output in that format. If not possible, return impossible. */
void ScalarConverter::fromChar(const std::string &s) {
    std::cout << "char: ";
    if (!isChar(s))
        std::cout << "impossible";
    else if (!std::isprint(s[0]))
        std::cout << "Non displayable";
    else
        std::cout << "'" << s[0] << "'";
    std::cout << std::endl;
}

void ScalarConverter::fromInt(const std::string &s) {
    // TODO
    std::cout << "int: ";
    if (!isInt(s))
        std::cout << "impossible";
    else
        std::cout << std::atoi(s.c_str());
    std::cout << std::endl;
}
void ScalarConverter::fromFloat(const std::string &s) {
    // TODO
    (void)s;
}
void ScalarConverter::fromDouble(const std::string &s) {
    // TODO
    (void)s;
}