/**
 * @file ClapTrap.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief To me, it looks like nothing but a crocodile.
 *
 *
 */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
class ClapTrap {
   public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap();
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    const std::string& getName() const;
    unsigned int getHp() const;
    unsigned int getEp() const;
    unsigned int getAtk() const;

   protected:
    static const std::string DEFAULT_NAME;
    static const unsigned int BASE_HP;
    static const unsigned int BASE_EP;
    static const unsigned int BASE_ATK;
    std::string name;
    unsigned int hp;
    unsigned int ep;
    unsigned int atk;

   private:
    virtual void showName() const;
};

#endif