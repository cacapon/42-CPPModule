/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#define TEST_COUNT 9

#include <iostream>
#include <limits>

void waitEnter() {
    std::cout << "Press ENTER to continue...";
    if (std::cin.peek() == '\n') std::cin.get();
    std::cin.get();
}

template <typename FormType>
static void test(const std::string &testname, int grade) {
    std::cout << "<<<" << testname << ">>>" << std::endl;
    try {
        Bureaucrat b("TestMen", grade);
        FormType form("Alice");
        b.signForm(form);
        b.executeForm(form);
    } catch (std::exception &e) {
        std::cout << "[Exception caught]" << e.what() << std::endl;
    }
}

int main() {
    int i;
    while (true) {
        std::cout << "\033c" << std::flush;
        std::cout << "cmd?[0-" << TEST_COUNT - 1 << "]>>";
        if (!(std::cin >> i)) break;
        if (i < 0 || i > TEST_COUNT - 1) break;
        switch (i) {
            case 0:
                test<PresidentialPardonForm>("PresidentialPardon::OK", 1);
                break;
            case 1:
                test<PresidentialPardonForm>("PresidentialPardon::NG:Sign", 10);
                break;
            case 2:
                test<PresidentialPardonForm>("PresidentialPardon::NG:Exec",
                                             100);
                break;
            case 3:
                test<RobotomyRequestForm>("RobotomyReques::OK", 1);
                break;
            case 4:
                test<RobotomyRequestForm>("RobotomyReques::NG:Sign", 50);
                break;
            case 5:
                test<RobotomyRequestForm>("RobotomyReques::NG:Exec", 100);
                break;
            case 6:
                test<ShrubberyCreationForm>("ShrubberyCreation::OK", 1);
                break;
            case 7:
                test<ShrubberyCreationForm>("ShrubberyCreation::NG:Sign", 140);
                break;
            case 8:
                test<ShrubberyCreationForm>("ShrubberyCreation::NG:Exec", 150);
                break;
            default:
                std::cout << "Invalid command" << std::endl;
                break;
        }
        waitEnter();
    }
    std::cout << "test end" << std::endl;
    return 0;
}