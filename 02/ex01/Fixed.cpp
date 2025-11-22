/**
 * @file Fixed.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Fixed.hpp"

#include <cmath>
#include <iostream>

Fixed::Fixed() : val(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : val(other.val) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int i) : val(i << bits) {
    std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float f) : val(static_cast<int>(roundf(f * (1 << bits)))) {
    std::cout << "Float constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->setRawBits(other.getRawBits());
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
#ifdef DEBUG_LOG
    std::cout << "getRawBits member function called" << std::endl;
#endif
    return this->val;
};

void Fixed::setRawBits(int const raw) {
#ifdef DEBUG_LOG
    std::cout << "setRawBits member function called" << std::endl;
#endif
    this->val = raw;
}

float Fixed::toFloat() const {
    return (static_cast<float>(this->val) / (1 << this->bits));
}

int Fixed::toInt() const { return (this->val >> this->bits); }

std::ostream& operator<<(std::ostream& o, const Fixed& fixed) {
    o << fixed.toFloat();
    return (o);
}
