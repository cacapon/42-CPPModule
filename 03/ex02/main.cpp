/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "FragTrap.hpp"
#include <iostream>

int main(void) {
    {
        std::cout << "<ctor/dtor test>" << std::endl;
        FragTrap default_ctor = FragTrap();
        FragTrap name_ctor = FragTrap("NameCtor");
        FragTrap copy_ctor = FragTrap(default_ctor);
    }
    std::cout << "================" << std::endl;
    {
        // normal test
        std::cout << "<normal test>" << std::endl;
        FragTrap normal = FragTrap("Normal");
        normal.attack("Frag1");
        normal.takeDamage(1);
        normal.beRepaired(1);
        normal.highFivesGuys();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test1: Crap ep>" << std::endl;
        FragTrap ep1 = FragTrap("EPTest1");
        for (int i = 0; i < 5; i++) {
            ep1.attack("Enemy");
            ep1.beRepaired(1);
        }
        ep1.attack("Attack success");
        ep1.beRepaired(1);
        ep1.takeDamage(1);
        ep1.highFivesGuys();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test2: Scav ep>" << std::endl;
        FragTrap ep2 = FragTrap("EPTest2");
        for (int i = 0; i < 25; i++) {
            ep2.attack("Enemy");
            ep2.beRepaired(1);
        }
        ep2.attack("Attack success");
        ep2.beRepaired(1);
        ep2.takeDamage(1);
        ep2.highFivesGuys();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test3: Frag ep>" << std::endl;
        FragTrap ep3 = FragTrap("EPTest3");
        for (int i = 0; i < 50; i++) {
            ep3.attack("Enemy");
            ep3.beRepaired(1);
        }
        ep3.attack("Attack failed");
        ep3.beRepaired(1);
        ep3.takeDamage(1);
        ep3.highFivesGuys();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<hp test1: Clap hp>" << std::endl;
        FragTrap hp1 = FragTrap("HPTest1");
        hp1.takeDamage(10);
        hp1.attack("Attack Success");
        hp1.beRepaired(1);
        hp1.takeDamage(1);
        hp1.highFivesGuys();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<hp test2: Frag hp (= Scav hp)>" << std::endl;
        FragTrap hp2 = FragTrap("HPTest2");
        hp2.takeDamage(100);
        hp2.attack("Attack Failed");
        hp2.beRepaired(1);
        hp2.takeDamage(1);
        hp2.highFivesGuys();
    }
    std::cout << "================" << std::endl;
    return 0;
}