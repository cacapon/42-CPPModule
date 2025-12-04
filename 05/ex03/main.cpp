/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#define TEST_COUNT 4

#include <iostream>

#include "Intern.hpp"

void waitEnter() {
    std::cout << "Press ENTER to continue...";
    if (std::cin.peek() == '\n') std::cin.get();
    std::cin.get();
}

void test(const std::string& testname, const std::string& formname,
          const std::string& target) {
    std::cout << "<<<" << testname << ">>>" << std::endl;
    try {
        Intern i;
        Bureaucrat b("test-men", 1);
        AForm* f = i.makeForm(formname, target);
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    } catch (const std::exception& e) {
        std::cout << "[Exception caught]" << e.what() << std::endl;
    }
}

int main() {
    int i;
    std::string name;
    std::cout << "name?>>";
    std::cin >> name;
    while (true) {
        std::cout << "\033c" << std::flush;
        std::cout << name << "@cmd?[0-" << TEST_COUNT - 1 << "]>>";
        if (!(std::cin >> i)) break;
        if (i < 0 || i > TEST_COUNT - 1) break;
        switch (i) {
            case 0:
                test("make presidential test", "presidential pardon", name);
                break;
            case 1:
                test("make robotomy test", "robotomy request", name);
                break;
            case 2:
                test("make shrubbery test", "shrubbery creation", name);
                break;
            case 3:
                test("make exception test", "bad form", name);
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