/**
 * @file ScavTrap.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  public:
    ScavTrap();
    ScavTrap(const std::string &name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();
    void guardGate();

  protected:
    static const unsigned int HP = 100;
    static const unsigned int EP = 50;
    static const unsigned int ATK = 20;

  private:
    virtual void showName() const;
};

#endif