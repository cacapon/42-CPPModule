/**
 * @file Weapon.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief What an incredible weapon this is!
 * 
 * 
 */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        std::string getType(void);
        void        setType(std::string type);
    private:
        std::string type;
};

#endif