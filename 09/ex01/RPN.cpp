/**
 * @file RPN.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-08
 *
 *
 */

#include "RPN.hpp"

#include <cctype>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN& other) : _c(other._c) {}
RPN& RPN::operator=(const RPN& other) {
    if (&other != this) {
        _c = other._c;
    }
    return *this;
}
RPN::~RPN() {}
int RPN::expr(const std::string& rpn_str) {
    while (!_c.empty()) _c.pop();
    std::istringstream iss(rpn_str);
    std::string token;
    while (iss >> token) {
        if (!_validateToken(token))
            throw std::runtime_error("Error::expr::Invalid token:" + token);
        if (std::isdigit(token[0]))
            _c.push(token[0] - '0');
        else
            _calc(token);
    }
    if (!_validateResult())
        throw std::runtime_error("Error::expr::Two or more results");
    return _c.top();
}

/**
    pre: _c.size() >= 2
    pre: token[0] == '/' and b != 0
*/
void RPN::_calc(const std::string& token) {
    if (_c.size() < 2) throw std::runtime_error("Error::_calc:: _c.size() < 2");
    int result = 0;
    int b = _c.top();
    _c.pop();
    int a = _c.top();
    _c.pop();

    switch (token[0]) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            if (b == 0) throw std::runtime_error("Error::_calc:: 0 division.");
            result = a / b;
            break;
        default:
            throw std::runtime_error("Error::_calc::unknowntoken:" + token);
    }
    _c.push(result);
}

bool RPN::_validateToken(const std::string& token) const {
    if (token.empty()) return false;
    if (token.size() != 1) return false;
    std::string valid_chars = "0123456789+-*/";

    return valid_chars.find(token[0]) != std::string::npos;
}

bool RPN::_validateResult() const { return _c.size() == 1; }
