/**
 * @file HumanA.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief He carries weapons via the constructor.
 *        He is always armed.
 *
 */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA {
public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();
  void attack();

private:
  std::string name;
  Weapon &my_weapon;
};

#endif
