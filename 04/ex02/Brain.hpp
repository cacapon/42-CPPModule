/**
 * @file Brain.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
   public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

   private:
    static const int N;
    std::string ideas[100];
};

#endif