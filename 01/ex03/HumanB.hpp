/**
 * @file HumanB.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief He starts out unarmed.
 * 
 * 
 */

 #ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon& weapon);
    private:
        std::string name;
        Weapon*     my_weapon;
};

#endif