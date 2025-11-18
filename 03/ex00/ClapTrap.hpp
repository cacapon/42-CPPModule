/**
 * @file ClapTrap.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief To me, it looks like nothing but a crocodile.
 *
 *
 */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
class ClapTrap {
  public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName() const;
    unsigned int getHp() const;
    unsigned int getEp() const;
    unsigned int getAtk() const;

  private:
    std::string name;
    unsigned int hp;
    unsigned int ep;
    unsigned int atk;
    void showName();
};

#endif