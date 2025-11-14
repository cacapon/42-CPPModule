/**
 * @file zombieHorde.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Zombie.hpp"
#include <cstddef>

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0)
    return (NULL);
  Zombie *zombies = new Zombie[N];

  for (int i = 0; i < N; i++) {
    zombies[i].setName(name);
  }
  return (zombies);
}
