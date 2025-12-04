/**
 * @file RobotomyRequestForm.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
   public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const& executor) const;

   private:
    static const int REQUIRED_SIGN_GRADE;
    static const int REQUIRED_EXEC_GRADE;
    std::string target;
};

#endif