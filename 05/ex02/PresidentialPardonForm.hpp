/**
 * @file PresidentialPardonForm.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
   public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const& executor) const;

   private:
    static const int REQUIRED_SIGN_GRADE;
    static const int REQUIRED_EXEC_GRADE;
    std::string target;
};

#endif