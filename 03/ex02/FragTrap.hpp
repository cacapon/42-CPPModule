/**
 * @file FragTrap.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
  public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap &operator=(const FragTrap &other);
    ~FragTrap();
    void highFivesGuys(void);

  protected:
    static const unsigned int HP = 100;
    static const unsigned int EP = 100;
    static const unsigned int ATK = 30;

  private:
    virtual void showName() const;
};

#endif