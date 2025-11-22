/**
 * @file WrongAnimal.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief my first abs class.
 *
 *
 */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {
   public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();
    std::string getType() const;
    void makeSound() const;

   protected:
    std::string type;

   private:
};

#endif