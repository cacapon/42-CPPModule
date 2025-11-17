/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief for test verification
 *
 *
 */

#include "Point.hpp"
#include <iostream>

static void test(const char *name, const Point &a, const Point &b,
                 const Point &c, const Point &p) {
    std::cout << name << ": ";
    if (bsp(a, b, c, p))
        std::cout << "inside" << std::endl;
    else
        std::cout << "outside" << std::endl;
}

int main(void) {
    const Point a = Point(0.0f, 1.2f);
    const Point b = Point(1.5f, 0.0f);
    const Point c = Point(0.0f, 0.0f);

    std::cout << "a(" << a.getX() << "," << a.getY() << "),";
    std::cout << "a(" << b.getX() << "," << b.getY() << "),";
    std::cout << "a(" << c.getX() << "," << c.getY() << ")";
    std::cout << std::endl << std::endl;

    test("inside (0.3, 0.3)", a, b, c, Point(0.3f, 0.3f));
    test("on edge AB (0.5,0.5)", a, b, c, Point(0.5f, 0.5f));
    test("on vertex A (0,1)", a, b, c, Point(0.0f, 1.0f));

    test("outside (0, 1.1)", a, b, c, Point(0.0f, 1.1f));
    test("outside (0.7, 0.7)", a, b, c, Point(0.7f, 0.7f));
    test("outside (-0.5, 0)", a, b, c, Point(-0.5f, 0.0f));

    return (0);
}