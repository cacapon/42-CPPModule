/**
 * @file AForm.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
   public:
    class GradeTooHighException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    class NotSignedException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    AForm(const std::string& name, const int signed_grade,
          const int exec_grade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    void beSigned(Bureaucrat& b);
    const std::string& getName() const;
    bool getIsSigned() const;
    int getSignedGrade() const;
    int getExecGrade() const;
    virtual void execute(Bureaucrat const& executor) const = 0;

   protected:
    void checkExecutable(const Bureaucrat& executor) const;

   private:
    const std::string name;
    const int signed_grade;
    const int exec_grade;
    bool is_signed;
};

std::ostream& operator<<(std::ostream& o, const AForm& f);

#endif