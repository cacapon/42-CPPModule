/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>

#include "ClapTrap.hpp"

int main(void) {
    {
        std::cout << "<ctor/dtor test>" << std::endl;
        ClapTrap default_ctor;
        ClapTrap name_ctor("name ctor");
        ClapTrap copy_ctor(default_ctor);
        std::cout << "================" << std::endl;
    }
    {
        // normal test
        std::cout << "<normal test>" << std::endl;
        ClapTrap c1("Normal");
        c1.attack("Trap1");
        c1.takeDamage(1);
        c1.beRepaired(1);
        std::cout << "================" << std::endl;
    }
    {
        std::cout << "<ep test>" << std::endl;
        ClapTrap c2("EPTest");
        for (int i = 0; i < 5; i++) {
            c2.attack("Trap1");
            c2.beRepaired(1);
        }
        c2.attack("Attack Failed");
        c2.beRepaired(1);
        c2.takeDamage(1);
        std::cout << "================" << std::endl;
    }
    {
        std::cout << "<hp test>" << std::endl;
        ClapTrap c3("HPTest");
        c3.takeDamage(10);
        c3.attack("Attack Failed");
        c3.beRepaired(1);
        c3.takeDamage(1);
        std::cout << "================" << std::endl;
    }
    return 0;
}