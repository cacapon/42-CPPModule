/**
 * @file Brain.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Brain.hpp"

#include <iostream>
#include <string>

const int Brain::N = 100;

static void ShowLog(const std::string detail) {
    std::cout << "Brain::" << detail << std::endl;
}

Brain::Brain() {
    ShowLog("ctor");
    for (int i = 0; i < Brain::N; i++) this->ideas[i] = "";
}

Brain::Brain(const Brain &other) {
    ShowLog("copy ctor");
    for (int i = 0; i < Brain::N; i++) {
        this->ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other) {
    ShowLog("operator=");
    if (this != &other) {
        for (int i = 0; i < Brain::N; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() { ShowLog("dtor"); }