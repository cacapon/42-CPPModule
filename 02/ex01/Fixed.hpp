/**
 * @file Fixed.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed(const int i);
        Fixed(const float f);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
    private:
        int val;
        static const int bits = 8;
};

std::ostream    &operator<<(std::ostream &o, const Fixed &fixed);

#endif