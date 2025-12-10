/**
 * @file ScalarConverter.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <cstdlib>
#include <iostream>
#include <string>

const std::string ScalarConverter::kPseudo[8] = {
    "nan", "inf", "+inf", "-inf", "nanf", "inff", "+inff", "-inff"};
const int ScalarConverter::kPseudoFloatStart = 4;

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
    if (std::isdigit(c)) return false;
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

// note:
// FLT_MIN is a number infinitely close to zero. Therefore, it cannot be used
// for minimum value checks.
// Since the maximum and minimum values of float are symmetrical,
// -FLT_MAX represents the minimum value.
bool ScalarConverter::isFloat(const std::string &s) {
    if (!regexFloat(s)) return false;
    double d = std::strtod(s.c_str(), NULL);
    return -FLT_MAX <= d && d <= FLT_MAX;
}

bool ScalarConverter::isDouble(const std::string &s) {
    if (!regexDouble(s)) return false;
    errno = 0;
    std::strtod(s.c_str(), NULL);
    return errno != ERANGE;
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
    while (i < s.length() && std::isdigit(static_cast<unsigned char>(s[i])))
        i++;
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
    size_t dot = s.find('.');
    if (dot == std::string::npos) return true;

    size_t i = dot + 1;
    size_t end = (s[s.length() - 1] == 'f') ? s.length() - 2 : s.length() - 1;

    for (; i < end; i++)
        if (s[i] != '0') return false;
    return true;
}

int ScalarConverter::getKeywordIndex(const std::string &s) {
    size_t n = sizeof(kPseudo) / sizeof(kPseudo[0]);
    for (size_t i = 0; i < n; i++) {
        if (s == kPseudo[i]) return i;
    }
    return -1;
}

std::string ScalarConverter::extractIntegerPart(const std::string &s) {
    size_t pos = s.find('.');
    if (pos == std::string::npos) return s;
    return s.substr(0, pos);
}

/* Output in that format. If not possible, return impossible. */

/**
 * @brief
 *
 * @param s
 * @note Output range: 0-127 or 1 character
 */
void ScalarConverter::fromChar(const std::string &s) {
    std::cout << "char: ";
    if (isChar(s)) {
        unsigned char c = static_cast<unsigned char>(s[0]);
        if (std::isprint(c))
            std::cout << "'" << c << "'";
        else
            std::cout << "Non displayable";
        std::cout << std::endl;
        return;
    }

    if (isInt(s) || isFloat(s) || isDouble(s)) {
        double d = std::strtod(s.c_str(), NULL);
        // d != d is nan check.
        if (!(0 <= d && d <= 127) || d != d) {
            std::cout << "impossible" << std::endl;
            return;
        }

        unsigned char c = static_cast<unsigned char>(d);
        if (std::isprint(c))
            std::cout << "'" << c << "'";
        else
            std::cout << "Non displayable";
        std::cout << std::endl;
        return;
    }
    std::cout << "impossible" << std::endl;
}

void ScalarConverter::fromInt(const std::string &s) {
    std::cout << "int: ";
    if (!isInt(s))
        std::cout << "impossible";
    else
        std::cout << std::atoi(s.c_str());
    std::cout << std::endl;
}

void ScalarConverter::fromFloat(const std::string &s) {
    int index = getKeywordIndex(s);
    std::cout << "float: ";
    if (index != -1) {
        if (kPseudoFloatStart <= index)
            std::cout << kPseudo[index] << std::endl;
        else
            std::cout << kPseudo[index] << "f" << std::endl;
        return;
    }
    if (isInt(s)) {
        int i = std::atoi(s.c_str());
        std::cout << i << ".0f" << std::endl;
        return;
    }
    if (isFloat(s) || isDouble(s)) {
        double d = std::strtod(s.c_str(), NULL);
        // d != d is nan check.
        if (!(-FLT_MAX <= d && d <= FLT_MAX) || d != d) {
            std::cout << "impossible" << std::endl;
            return;
        }
        std::cout << d << "f" << std::endl;
        return;
    }
    std::cout << "impossible" << std::endl;
}

void ScalarConverter::fromDouble(const std::string &s) {
    int index = getKeywordIndex(s);
    std::cout << "double: ";
    if (index != -1) {
        // TODO
        if (kPseudoFloatStart <= index)
            std::cout << kPseudo[index - kPseudoFloatStart] << std::endl;
        else
            std::cout << kPseudo[index] << std::endl;
        return;
    }
    if (isInt(s)) {
        int i = std::atoi(s.c_str());
        std::cout << i << ".0" << std::endl;
        return;
    }
    if (isFloat(s) || isDouble(s)) {
        double d = std::strtod(s.c_str(), NULL);
        // d != d is nan check.
        if (d != d) {
            std::cout << "impossible" << std::endl;
            return;
        }
        std::cout << d << std::endl;
        return;
    }
    std::cout << "impossible" << std::endl;
}