/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief Now it's time to swing the club.
 *
 *
 */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
  {
    Weapon club = Weapon("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
  }
  {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
  }
  {
    HumanB joe("Knuckle Joe");
    joe.attack();
  }
  return 0;
}