/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

int main(void) {
    {
        std::cout << "<ctor/dtor test>" << std::endl;
        ClapTrap *default_ctor = new ClapTrap();
        ClapTrap *name_ctor = new ClapTrap("name ctor");
        ClapTrap *copy_ctor = new ClapTrap(*default_ctor);
        delete default_ctor;
        delete name_ctor;
        delete copy_ctor;
        std::cout << "================" << std::endl;
    }
    {
        // normal test
        std::cout << "<normal test>" << std::endl;
        ClapTrap *c1 = new ClapTrap("Normal");
        c1->attack("Trap1");
        c1->takeDamage(1);
        c1->beRepaired(1);
        delete c1;
        std::cout << "================" << std::endl;
    }
    {
        std::cout << "<ep test>" << std::endl;
        ClapTrap *c2 = new ClapTrap("EPTest");
        for (int i = 0; i < 5; i++) {
            c2->attack("Trap1");
            c2->beRepaired(1);
        }
        c2->attack("Attack Failed");
        c2->beRepaired(1);
        c2->takeDamage(1);
        delete c2;
        std::cout << "================" << std::endl;
    }
    {
        std::cout << "<hp test>" << std::endl;
        ClapTrap *c3 = new ClapTrap("HPTest");
        c3->takeDamage(10);
        c3->attack("Attack Failed");
        c3->beRepaired(1);
        c3->takeDamage(1);
        delete c3;
        std::cout << "================" << std::endl;
    }
    return 0;
}