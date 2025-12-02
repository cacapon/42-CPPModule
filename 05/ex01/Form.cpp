/**
 * @file Form.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Form.hpp"

#include "Bureaucrat.hpp"

static void ShowLog(const std::string detail) {
#ifdef DEBUG
    std::cout << "Form::" << detail << std::endl;
#else
    (void)detail;
#endif
}

Form::Form(const std::string& name, const int signed_grade,
           const int exec_grade)
    : name(name), signed_grade(signed_grade), exec_grade(exec_grade) {
    if (exec_grade < 1 || signed_grade < 1) throw GradeTooHighException();
    if (exec_grade > 150 || signed_grade > 150) throw GradeTooLowException();
    this->is_signed = false;
    ShowLog("default ctor");
}

Form::Form(const Form& other)
    : name(other.name),
      signed_grade(other.signed_grade),
      exec_grade(other.exec_grade),
      is_signed(other.is_signed) {
    ShowLog("copy ctor");
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->is_signed = other.is_signed;
    }
    ShowLog("operator=");
    return *this;
}

Form::~Form() { ShowLog("dtor"); }

void Form::beSigned(Bureaucrat& b) {
    if (b.getGrade() <= this->getSignedGrade())
        this->is_signed = true;
    else
        throw Form::GradeTooLowException();
}

const std::string& Form::getName() const { return this->name; }
bool Form::getIsSigned() const { return this->is_signed; }
int Form::getSignedGrade() const { return this->signed_grade; }
int Form::getExecGrade() const { return this->exec_grade; }

const char* Form::GradeTooHighException::what() const throw() {
    return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form::GradeTooLowException";
}

std::ostream& operator<<(std::ostream& o, const Form& form) {
    o << "Form(name=" << form.getName()
      << ", signed_grade=" << form.getSignedGrade()
      << ", exec_grade=" << form.getExecGrade()
      << ", is_signed=" << form.getIsSigned() << ")";
    return (o);
}
