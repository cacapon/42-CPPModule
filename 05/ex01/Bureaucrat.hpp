/**
 * @file Bureaucrat.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat {
   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    void promote();
    void demote();
    void signForm(Form& f);
    const std::string& getName() const;
    int getGrade() const;

   private:
    const std::string name;
    int grade;
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif