/**
 * @file Bureaucrat.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "Bureaucrat::" << detail << std::endl;
#else
    (void)detail;
#endif
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade) {
    if (grade < 1) throw GradeTooHighException();
    if (grade > 150) throw GradeTooLowException();
    ShowLog("name ctor");
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade) {
    ShowLog("copy ctor");
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    ShowLog("operator=");
    return *this;
}

Bureaucrat::~Bureaucrat() { ShowLog("dtor"); }

void Bureaucrat::promote() {
    if (grade <= 1) throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::demote() {
    if (grade >= 150) throw GradeTooLowException();
    this->grade++;
}

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << this->getName() << " couldn't sign " << f.getName()
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName()
                  << std::endl;
    } catch (std::exception& e) {
        std::cout << this->getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

const std::string& Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat::GradeTooLowException";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (o);
}
