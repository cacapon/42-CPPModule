/**
 * @file PresidentialPardonForm.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

const int PresidentialPardonForm::REQUIRED_SIGN_GRADE = 25;
const int PresidentialPardonForm::REQUIRED_EXEC_GRADE = 5;

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "PresidentialPardonForm::" << detail << std::endl;
#else
    (void)detail;
#endif
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE),
      target(target) {
    ShowLog("default ctor");
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other), target(other.target) {
    ShowLog("copy ctor");
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
    ShowLog("operator=");
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { ShowLog("dtor"); }

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    checkExecutable(executor);
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}