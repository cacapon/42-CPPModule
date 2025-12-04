/**
 * @file AForm.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "AForm.hpp"

#include <iostream>

#include "Bureaucrat.hpp"

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "AForm::" << detail << std::endl;
#else
    (void)detail;
#endif
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm::GradeTooLowException";
}

const char* AForm::NotSignedException::what() const throw() {
    return "AForm::NotSignedException";
}

AForm::AForm(const std::string& name, const int signed_grade,
             const int exec_grade)
    : name(name), signed_grade(signed_grade), exec_grade(exec_grade) {
    if (exec_grade < 1 || signed_grade < 1) throw GradeTooHighException();
    if (exec_grade > 150 || signed_grade > 150) throw GradeTooLowException();
    this->is_signed = false;
    ShowLog("default ctor");
}

AForm::AForm(const AForm& other)
    : name(other.name),
      signed_grade(other.signed_grade),
      exec_grade(other.exec_grade),
      is_signed(other.is_signed) {
    ShowLog("copy ctor");
}

// name, signed_grade, and exec_grade are const, so they cannot be copied.
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->is_signed = other.is_signed;
    }
    ShowLog("operator=");
    return *this;
}

AForm::~AForm() { ShowLog("dtor"); }

void AForm::beSigned(Bureaucrat& b) {
    ShowLog("beSigned");
    if (b.getGrade() > this->getSignedGrade())
        throw AForm::GradeTooLowException();
    this->is_signed = true;
}

const std::string& AForm::getName() const { return this->name; }
bool AForm::getIsSigned() const { return this->is_signed; }
int AForm::getSignedGrade() const { return this->signed_grade; }
int AForm::getExecGrade() const { return this->exec_grade; }

void AForm::checkExecutable(const Bureaucrat& executor) const {
    ShowLog("checkExecutable");
    if (!this->is_signed) throw NotSignedException();
    if (executor.getGrade() > this->exec_grade) throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& o, const AForm& f) {
    ShowLog("operator<<");
    o << "AForm(name=" << f.getName() << ", signed_grade=" << f.getSignedGrade()
      << ", exec_grade=" << f.getExecGrade()
      << ", is_signed=" << f.getIsSigned() << ")";
    return (o);
}
