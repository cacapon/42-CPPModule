/**
 * @file RobotomyRequestForm.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

static bool randomHalf() {
    return std::rand() % 2 == 0;  // 50%でtrue, false
}

const int RobotomyRequestForm::REQUIRED_SIGN_GRADE = 72;
const int RobotomyRequestForm::REQUIRED_EXEC_GRADE = 45;

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "RobotomyRequestForm::" << detail << std::endl;
#else
    (void)detail;
#endif
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", REQUIRED_SIGN_GRADE, REQUIRED_EXEC_GRADE),
      target(target) {
    ShowLog("default ctor");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target) {
    ShowLog("copy ctor");
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
    ShowLog("operator=");
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { ShowLog("dtor"); }

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    checkExecutable(executor);
    std::cout << "whrrrrr!!!...";
    if (randomHalf())
        std::cout << "Success! You've become a 24/7 working robot-like "
                     "corporate slave!"
                  << std::endl;
    else
        std::cout << "Failure... Let's contribute to the company as we are."
                  << std::endl;
}
