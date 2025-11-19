/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "DiamondTrap.hpp"
#include <iostream>
#include <ostream>

int main(void) {
    {
        std::cout << "<ctor/dtor test>" << std::endl;
        DiamondTrap default_ctor = DiamondTrap();
        DiamondTrap name_ctor = DiamondTrap("NameCtor");
        DiamondTrap copy_ctor = DiamondTrap(default_ctor);
    }
    std::cout << "================" << std::endl;
    {
        // normal test
        std::cout << "<normal test>" << std::endl;
        DiamondTrap normal = DiamondTrap("Normal");
        normal.attack("Diamond1");
        normal.ScavTrap::takeDamage(1);
        normal.ScavTrap::beRepaired(1);
        normal.whoAmI();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test1: Crap ep>" << std::endl;
        DiamondTrap ep1 = DiamondTrap("EPTest1");
        for (int i = 0; i < 5; i++) {
            ep1.attack("Enemy");
            ep1.ScavTrap::beRepaired(1);
        }
        ep1.attack("Attack success");
        ep1.ScavTrap::beRepaired(1);
        ep1.ScavTrap::takeDamage(1);
        ep1.whoAmI();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test2: Scav ep>" << std::endl;
        DiamondTrap ep2 = DiamondTrap("EPTest2");
        for (int i = 0; i < 25; i++) {
            ep2.attack("Enemy");
            ep2.ScavTrap::beRepaired(1);
        }
        ep2.attack("Attack failed");
        ep2.ScavTrap::beRepaired(1);
        ep2.ScavTrap::takeDamage(1);
        ep2.whoAmI();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test3: Flag ep>" << std::endl;
        DiamondTrap ep3 = DiamondTrap("EPTest3");
        for (int i = 0; i < 50; i++) {
            ep3.attack("Enemy");
            ep3.ScavTrap::beRepaired(1);
        }
        ep3.attack("Attack failed");
        ep3.ScavTrap::beRepaired(1);
        ep3.ScavTrap::takeDamage(1);
        ep3.whoAmI();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<hp test1: Clap hp>" << std::endl;
        DiamondTrap hp1 = DiamondTrap("HPTest1");
        hp1.ScavTrap::takeDamage(10);
        hp1.attack("Attack Success");
        hp1.ScavTrap::beRepaired(1);
        hp1.ScavTrap::takeDamage(1);
        hp1.whoAmI();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<hp test2: Flag hp (= Scav hp)>" << std::endl;
        DiamondTrap hp2 = DiamondTrap("HPTest2");
        hp2.ScavTrap::takeDamage(100);
        hp2.attack("Attack Failed");
        hp2.ScavTrap::beRepaired(1);
        hp2.ScavTrap::takeDamage(1);
        hp2.whoAmI();
    }
    std::cout << "================" << std::endl;
    return 0;
}