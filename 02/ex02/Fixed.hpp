/**
 * @file Fixed.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef FIXED_HPP
#define FIXED_HPP
// #define DEBUG_LOG
#include <ostream>

class Fixed {
   public:
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed(const int i);
    Fixed(const float f);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // comparison operators
    bool operator>(const Fixed& other);
    bool operator<(const Fixed& other);
    bool operator>=(const Fixed& other);
    bool operator<=(const Fixed& other);
    bool operator==(const Fixed& other);
    bool operator!=(const Fixed& other);

    // arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // increment & decrement operators
    Fixed& operator++();
    Fixed operator++(int);
    Fixed& operator--();
    Fixed operator--(int);

    // static member functions
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);

    // menber functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

   private:
    int val;
    static const int bits = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed);

#endif