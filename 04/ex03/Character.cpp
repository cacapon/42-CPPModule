/**
 * @file Character.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Character.hpp"

#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

const int Character::MATERIA_MAX = 4;

static std::string itos(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

Character::Character() {
    ShowLog("Character", "default ctor");
    this->name = "default";
    for (int i = 0; i < MATERIA_MAX; i++) inventory[i] = NULL;
}

Character::Character(const std::string& name) {
    ShowLog("Character", "name ctor");
    this->name = name;
    for (int i = 0; i < MATERIA_MAX; i++) inventory[i] = NULL;
}

Character::Character(const Character& other) {
    ShowLog("Character", "copy ctor");
    name = other.getName();
    for (int i = 0; i < MATERIA_MAX; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    ShowLog("Character", "operator=");
    if (this != &other) {
        this->name = other.getName();
        for (int i = 0; i < MATERIA_MAX; i++) {
            if (this->inventory[i]) delete inventory[i];
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    ShowLog("Character", "dtor");
    for (int i = 0; i < MATERIA_MAX; i++) {
        if (this->inventory[i]) delete this->inventory[i];
    }
}

std::string const& Character::getName() const { return this->name; }

void Character::equip(AMateria* m) {
    if (!m) {
        ShowLog("Character", "equip:Error:Materia is NULL.");
        return;
    }
    for (int i = 0; i < MATERIA_MAX; i++) {
        if (!this->inventory[i]) {
            ShowLog("Character", "equip:" + m->getType());
            this->inventory[i] = m;
            return;
        }
    }
    ShowLog("Character", "equip:Error:Inventory is full.");
}

void Character::unequip(int idx) {
    if (idx < 0 || MATERIA_MAX <= idx) {
        ShowLog("Character", "unequip:Error:Invalid index is " + itos(idx));
        return;
    }
    if (!this->inventory[idx]) {
        ShowLog("Character",
                "unequip:Error:The index for that inventory is empty.");
        return;
    }
    ShowLog("Character", "unequip:I unequiped the " +
                             this->inventory[idx]->getType() +
                             " that was attached to number " + itos(idx) + ".");
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || MATERIA_MAX <= idx) {
        ShowLog("Character", "use:Error:Invalid index is " + itos(idx));
        return;
    }
    if (!this->inventory[idx]) {
        ShowLog("Character",
                "use:Error:The index for that inventory is empty.");
        return;
    }
    ShowLog("Character", "use:" + this->name + " used " +
                             this->inventory[idx]->getType() + ".");
    this->inventory[idx]->use(target);
}