/**
 * @file FlagTrap.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class FlagTrap : public ClapTrap {
  public:
    FlagTrap();
    FlagTrap(const std::string &name);
    FlagTrap(const FlagTrap &other);
    FlagTrap &operator=(const FlagTrap &other);
    ~FlagTrap();
    void highFivesGuys(void);

  protected:
    static const unsigned int HP = 100;
    static const unsigned int EP = 100;
    static const unsigned int ATK = 30;

  private:
    virtual void showName() const;
};

#endif