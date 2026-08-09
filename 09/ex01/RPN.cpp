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

RPN::RPNError::RPNError() : _detail("Error") {}

RPN::RPNError::RPNError(const std::string& detail) : _detail(detail) {}

RPN::RPNError::RPNError(const RPNError& other) : _detail(other._detail) {}

RPN::RPNError& RPN::RPNError::operator=(const RPNError& other) {
    if (&other != this) {
        _detail = other._detail;
    }
    return *this;
}

RPN::RPNError::~RPNError() throw() {}

const char* RPN::RPNError::what() const throw() {
#ifdef DEBUG
    return _detail.c_str();
#else
    return "Error";
#endif
}

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
            throw RPNError("Error::expr::Invalid token:" + token);
        if (std::isdigit(token[0]))
            _c.push(token[0] - '0');
        else
            _calc(token);
    }
    if (!_validateResult()) throw RPNError("Error::expr::Two or more results");
    return _c.top();
}

/**
    pre: _c.size() >= 2
    pre: token[0] == '/' and b != 0
*/
void RPN::_calc(const std::string& token) {
    if (_c.size() < 2) throw RPNError("Error::_calc:: _c.size() < 2");
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
            if (b == 0) throw RPNError("Error::_calc:: 0 division.");
            result = a / b;
            break;
        default:
            throw RPNError("Error::_calc::unknowntoken:" + token);
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
