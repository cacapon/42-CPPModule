/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

bool to_int(const std::string &s, int &out) {
  std::stringstream ss(s);
  ss >> out;
  if (ss.fail() || !ss.eof())
    return false;
  return true;
}

int main(int ac, char **av) {
  int N;
  Zombie *horde;

  (void)ac;
  if (!to_int(av[1], N))
    return (std::cout << "invalid num\n", 1);
  horde = zombieHorde(N, "zombie");
  for (int i = 0; i < N; i++) {
    horde[i].announce();
  }
  delete[] horde;
  return (0);
}