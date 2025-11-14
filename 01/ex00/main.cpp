/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Zombie.hpp"
#include <sstream>

std::string to_string(int i) {
  std::stringstream ss;
  ss << i;
  return (ss.str());
}

int main(void) {
  const int N = 100;
  Zombie **zombies = new Zombie *[N];

  for (int i = 0; i < N; i++) {
    zombies[i] = newZombie("Zombie" + to_string(i));
    zombies[i]->announce();
    randomChump("Chump" + to_string(i));
  }

  for (int i = 0; i < N; i++) {
    delete zombies[i];
  }
  delete[] zombies;

  return (0);
}