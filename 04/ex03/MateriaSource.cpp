/**
 * @file MateriaSource.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "MateriaSource.hpp"

#include <cstddef>
#include <iostream>

const int MateriaSource::MATERIA_MAX = 4;

static void ShowLog(const std::string detail) {
    std::cout << "MateriaSource::" << detail << std::endl;
}

MateriaSource::MateriaSource() {
    ShowLog("default ctor");
    for (int i = 0; i < MATERIA_MAX; i++) this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    ShowLog("copy ctor");
    for (int i = 0; i < MATERIA_MAX; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
        else
            this->inventory[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    ShowLog("operator=");
    if (this != &other) {
        for (int i = 0; i < MATERIA_MAX; i++) {
            if (this->inventory[i]) delete this->inventory[i];
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    ShowLog("dtor");
    for (int i = 0; i < MATERIA_MAX; i++) {
        if (this->inventory[i]) delete this->inventory[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < MATERIA_MAX; i++) {
        if (!this->inventory[i]) {
            this->inventory[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
    for (int i = 0; i < MATERIA_MAX; i++) {
        if (this->inventory[i] && this->inventory[i]->getType() == type)
            return this->inventory[i]->clone();
    }
    return NULL;
}