/**
 * @file Intern.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
class AForm;

class Intern {
   public:
    class MakeFormException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    AForm* makeForm(const std::string& form_name, const std::string& target);
};

#endif