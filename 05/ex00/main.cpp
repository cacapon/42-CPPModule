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
#define TEST_COUNT 9

void waitEnter() {
    std::cout << "Press ENTER to continue...";
    if (std::cin.peek() == '\n') std::cin.get();
    std::cin.get();
}

static void test_promote(Bureaucrat &b, int count) {
    std::cout << "test_promote::" << b.getName() << "::" << count << std::endl;
    for (int i = 0; i < count; i++) b.promote();
    std::cout << b << std::endl;
}

static void test_demote(Bureaucrat &b, int count) {
    std::cout << "test_demote::" << b.getName() << "::" << count << std::endl;
    for (int i = 0; i < count; i++) b.demote();
    std::cout << b << std::endl;
}

static void test(const std::string &testName, int c_i, int p_i, int d_i,
                 void (*promote)(Bureaucrat &b, int i),
                 void (*demote)(Bureaucrat &b, int i)) {
    try {
        std::cout << "<<<" << testName << ">>>" << std::endl;
        Bureaucrat b(testName, c_i);
        if (promote) promote(b, p_i);
        if (demote) demote(b, d_i);
    } catch (std::exception &e) {
        std::cout << "[Exception caught]" << e.what() << std::endl;
    }
}

static void test_assign() {
    std::cout << "<<<operator= test>>>" << std::endl;

    Bureaucrat a("Alice", 42);
    Bureaucrat b("Bob", 100);

    std::cout << "Before: " << a << " | " << b << std::endl;
    b = a;
    std::cout << "After:  " << a << " | " << b << std::endl;
}

static void test_copy() {
    std::cout << "<<<copy ctor test>>>" << std::endl;

    Bureaucrat a("Alice", 42);
    Bureaucrat b(a);

    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
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
                test("Normal test", 10, 1, 1, test_promote, test_demote);
                break;
            case 1:
                test("Exception ctor too high test", 0, 0, 0, NULL, NULL);
                break;
            case 2:
                test("Exception ctor too low test", 151, 0, 0, NULL, NULL);
                break;
            case 3:
                test("Exception promote test", 10, 10, 0, test_promote, NULL);
                break;
            case 4:
                test("Exception demote test", 140, 15, 0, NULL, test_demote);
                break;
            case 5:
                test_assign();
                break;
            case 6:
                test_copy();
                break;
            case 7:
                test("Promote edge test", 2, 1, 0, test_promote, NULL);
                break;
            case 8:
                test("Demote edge test", 149, 0, 1, NULL, test_demote);
                break;
        }
        waitEnter();
    }
    std::cout << "test end" << std::endl;
    return 0;
}