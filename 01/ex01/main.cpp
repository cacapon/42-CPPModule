/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#include "Zombie.hpp"

int main(void) {
    const int N = 100;
    Zombie *horde;

    horde = zombieHorde(N, "zombie");
    for (int i=0; i<N; i++) {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}