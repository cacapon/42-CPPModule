/**
 * @file RPN.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-08
 *
 *
 */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
private:
    std::stack<int> _c;
    bool _validateToken(const std::string& token) const;
    bool _validateResult() const;

    void _calc(const std::string& token);

public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    int expr(const std::string& rpn_str);
};

#endif
