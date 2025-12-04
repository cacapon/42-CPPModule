/**
 * @file ShrubberyCreationForm.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
   public:
    class FileOpenException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const& executor) const;

   private:
    static const int REQUIRED_SIGN_GRADE;
    static const int REQUIRED_EXEC_GRADE;
    std::string target;
};

#endif