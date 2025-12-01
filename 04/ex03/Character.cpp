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

static void ShowLog(const std::string detail) {
    std::cout << "Character::" << detail << std::endl;
}

static std::string itos(int n) {
    std::stringstream ss;
    ss << n;
    return ss.str();
}

Character::Character() {
    ShowLog("default ctor");
    this->name = "default";
    for (int i = 0; i < this->MATERIA_MAX; i++) inventory[i] = NULL;
}

Character::Character(const std::string& name) {
    ShowLog("name ctor");
    this->name = name;
    for (int i = 0; i < this->MATERIA_MAX; i++) inventory[i] = NULL;
}

Character::Character(const Character& other) {
    ShowLog("copy ctor");
    name = other.getName();
    for (int i = 0; i < this->MATERIA_MAX; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    ShowLog("operator=");
    if (this != &other) {
        this->name = other.getName();
        for (int i = 0; i < this->MATERIA_MAX; i++) {
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
    ShowLog("dtor");
    for (int i = 0; i < this->MATERIA_MAX; i++) {
        if (this->inventory[i]) delete this->inventory[i];
    }
}

std::string const& Character::getName() const { return this->name; }

void Character::equip(AMateria* m) {
    if (!m) {
        ShowLog("equip:Error:Materia is NULL.");
        return;
    }
    for (int i = 0; i < this->MATERIA_MAX; i++) {
        if (!this->inventory[i]) {
            ShowLog("equip:" + m->getType());
            this->inventory[i] = m;
            return;
        }
    }
    ShowLog("equip:Error:Inventory is full.");
}

void Character::unequip(int idx) {
    if (idx < 0 || this->MATERIA_MAX <= idx) {
        ShowLog("unequip:Error:Invalid index is " + itos(idx));
        return;
    }
    if (!this->inventory[idx]) {
        ShowLog("unequip:Error:The index for that inventory is empty.");
        return;
    }
    ShowLog("unequip:I unequiped the " + this->inventory[idx]->getType() +
            " that was attached to number " + itos(idx) + ".");
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || this->MATERIA_MAX <= idx) {
        ShowLog("use:Error:Invalid index is " + itos(idx));
        return;
    }
    if (!this->inventory[idx]) {
        ShowLog("use:Error:The index for that inventory is empty.");
        return;
    }
    ShowLog("use:" + this->name + " used " + this->inventory[idx]->getType() +
            ".");
    this->inventory[idx]->use(target);
}