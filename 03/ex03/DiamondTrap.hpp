/**
 * @file DiamondTrap.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <string>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();
        void attack(const std::string &target);
        void whoAmI();

        private:
        std::string name;
        virtual void showName() const;
};

#endif