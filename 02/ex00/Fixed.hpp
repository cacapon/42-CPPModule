/**
 * @file Fixed.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#ifndef FIXED_HPP
# define FIXED_HPP


class Fixed
{
    public:
        Fixed(void);
        Fixed(const Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
    private:
        int fixed_point_num;
        static const int fractional_bits = 8;
};

#endif