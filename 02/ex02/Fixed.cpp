/**
 * @file Fixed.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->val = 0;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::Fixed(const int i)
    : val(i << bits) {};

Fixed::Fixed(const float f)
    : val(static_cast<int>(roundf(f * (1 << bits)))) {};

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->setRawBits(other.getRawBits());
    }
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

bool Fixed::operator>(const Fixed &other)
{
    return (this->val > other.val);
}

bool Fixed::operator<(const Fixed &other)
{
    return (this->val < other.val);
}

bool Fixed::operator>=(const Fixed &other)
{
    return (this->val >= other.val);
}

bool Fixed::operator<=(const Fixed &other)
{
    return (this->val <= other.val);
}

bool Fixed::operator==(const Fixed &other)
{
    return (this->val == other.val);
}

bool Fixed::operator!=(const Fixed &other)
{
    return (this->val != other.val);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed tmp;
    tmp.setRawBits(this->getRawBits() + other.getRawBits());
    return (tmp);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed tmp;
    tmp.setRawBits(this->getRawBits() - other.getRawBits());
    return (tmp);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed tmp;
    long long mul;

    mul = (long long)this->getRawBits() * (long long)other.getRawBits();
    mul >>= this->bits;
    tmp.setRawBits(static_cast<int>(mul));
    return (tmp);
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed tmp;
    long long div;

    div = ((long long)this->getRawBits() << this->bits) / other.getRawBits();
    tmp.setRawBits(static_cast<int>(div));
    return (tmp);
}

Fixed& Fixed::operator++()
{
    this->val += 1;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    this->val += 1;
    return (old);
}

Fixed& Fixed::operator--()
{
    this->val -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    this->val -= 1;
    return (old);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a.getRawBits() < b.getRawBits() ? a : b);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->val;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->val = raw;
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->val) / (1 << this->bits));
}

int Fixed::toInt(void) const
{
    return (this->val >> this->bits);
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed)
{
    o << fixed.toFloat();
    return (o);
}
