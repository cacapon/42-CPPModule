/**
 * @file Form.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef FORM_HPP
#define FORM_HPP
#include <exception>
#include <string>

class Bureaucrat;

class Form {
   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Form(const std::string& name, const int signed_grade, const int exec_grade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();
    void beSigned(Bureaucrat& b);
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignedGrade() const;
    int getExecGrade() const;

   private:
    const std::string name;
    const int signed_grade;
    const int exec_grade;
    bool is_signed;
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif