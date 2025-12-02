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

class Bureaucrat {
   public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    void promote();
    void demote();
    const std::string& getName() const;
    int getGrade() const;

   private:
    const std::string name;
    int grade;
};

class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
};

class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& Bureaucrat);

#endif