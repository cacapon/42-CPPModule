/**
 * @file Cure.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "log.hpp"

class Cure : public AMateria {
   public:
    Cure();
    Cure(const Cure& other);
    Cure& operator=(const Cure& other);
    ~Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif