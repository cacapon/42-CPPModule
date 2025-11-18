/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "ScavTrap.hpp"
#include <iostream>
#include <ostream>

int main(void) {
    {
        std::cout << "<ctor/dtor test>" << std::endl;
        ScavTrap default_ctor = ScavTrap();
        ScavTrap name_ctor = ScavTrap("NameCtor");
        ScavTrap copy_ctor = ScavTrap(default_ctor);
    }
    std::cout << "================" << std::endl;
    {
        // normal test
        std::cout << "<normal test>" << std::endl;
        ScavTrap normal = ScavTrap("Normal");
        normal.attack("Scav1");
        normal.takeDamage(1);
        normal.beRepaired(1);
        normal.guardGate();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test1: Crap ep>" << std::endl;
        ScavTrap ep1 = ScavTrap("EPTest1");
        for (int i = 0; i < 5; i++) {
            ep1.attack("Enemy");
            ep1.beRepaired(1);
        }
        ep1.attack("Attack success");
        ep1.beRepaired(1);
        ep1.takeDamage(1);
        ep1.guardGate();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<ep test2: Scav ep>" << std::endl;
        ScavTrap ep2 = ScavTrap("EPTest2");
        for (int i = 0; i < 25; i++) {
            ep2.attack("Enemy");
            ep2.beRepaired(1);
        }
        ep2.attack("Attack failed");
        ep2.beRepaired(1);
        ep2.takeDamage(1);
        ep2.guardGate();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<hp test1: Clap hp>" << std::endl;
        ScavTrap hp1 = ScavTrap("HPTest1");
        hp1.takeDamage(10);
        hp1.attack("Attack Success");
        hp1.beRepaired(1);
        hp1.takeDamage(1);
        hp1.guardGate();
    }
    std::cout << "================" << std::endl;
    {
        std::cout << "<hp test2: Scav hp>" << std::endl;
        ScavTrap hp2 = ScavTrap("HPTest2");
        hp2.takeDamage(100);
        hp2.attack("Attack Failed");
        hp2.beRepaired(1);
        hp2.takeDamage(1);
        hp2.guardGate();
    }
    std::cout << "================" << std::endl;
    return 0;
}