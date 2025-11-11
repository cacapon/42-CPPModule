/**
 * @file Fixed.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#include "Fixed.hpp"
# include <iostream>
# include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->val = 0;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int i)
    :val(i << bits){};

Fixed::Fixed(const float f)
    :val(static_cast<int>(roundf(f * (1 << bits)))){};

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->setRawBits(other.getRawBits());
    }
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->val;
};

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->val = raw;
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(this->val) / (1 << this->bits));
}

int     Fixed::toInt(void) const
{
    return (this->val >> this->bits);
}

std::ostream    &operator<<(std::ostream &o, const Fixed &fixed)
{
    o << fixed.toFloat();
    return (o);
}
