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

const std::string& Bureaucrat::getName() const { return this->name; }
int Bureaucrat::getGrade() const { return this->grade; }

const char* GradeTooHighException::what() const throw() {
    return "GradeTooHighException";
}

const char* GradeTooLowException::what() const throw() {
    return "GradeTooLowException";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& bureaucrat) {
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
      << ".";
    return (o);
}
