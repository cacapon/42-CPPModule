/**
 * @file Intern.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Intern.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// static functions;
static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "Intern::" << detail << std::endl;
#else
    (void)detail;
#endif
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

// static args
static const std::string formNames[] = {
    "presidential pardon", "robotomy request", "shrubbery creation"};

static const int FORM_COUNT = sizeof(formNames) / sizeof(formNames[0]);

static AForm* (*formCreators[])(const std::string&) = {
    &createPresidential, &createRobotomy, &createShrubbery};

const char* Intern::MakeFormException::what() const throw() {
    return "Intern::MakeFormException";
}

// public methods
Intern::Intern() { ShowLog("default ctor"); }

Intern::Intern(const Intern& other) {
    (void)other;
    ShowLog("copy ctor");
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    ShowLog("operator=");
    return *this;
}

Intern::~Intern() { ShowLog("dtor"); }

AForm* Intern::makeForm(const std::string& form_name,
                        const std::string& target) {
    for (int i = 0; i < FORM_COUNT; i++) {
        if (formNames[i] == form_name) {
            std::cout << "Intern creates " << form_name << std::endl;
            return formCreators[i](target);
        }
    }
    throw MakeFormException();
}