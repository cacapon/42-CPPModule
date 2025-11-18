/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ClapTrap.hpp"
int main(void) {
    {
        // normal test
        ClapTrap *c1 = new ClapTrap("Normal");
        c1->attack("Trap1");
        c1->takeDamage(1);
        c1->beRepaired(1);
        delete c1;
    }
    {
        // ep test
        ClapTrap *c2 = new ClapTrap("EPTest");
        for (int i = 0; i < 5; i++) {
            c2->attack("Trap1");
            c2->beRepaired(1);
        }
        c2->attack("Attack Failed");
        c2->beRepaired(1);
        c2->takeDamage(1);
        delete c2;
    }
    {
        // hp test
        ClapTrap *c3 = new ClapTrap("HPTest");
        c3->takeDamage(10);
        c3->attack("Attack Failed");
        c3->beRepaired(1);
        c3->takeDamage(1);
        delete c3;
    }
    return 0;
}