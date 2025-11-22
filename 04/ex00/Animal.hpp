/**
 * @file Animal.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief my first abs class.
 *
 *
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
   public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();
    std::string getType() const;
    virtual void makeSound() const;

   protected:
    std::string type;

   private:
};

#endif