/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief for test verification
 * 
 * 
 */

#include "Point.hpp"
#include <iostream>

int main(void)
{
    const Point a = Point(0.0, 1.0);
    const Point b = Point(1.0, 0.0);
    const Point c = Point(0.0, 0.0);
    const Point p = Point(0.3, 0.3);

    if (bsp(a,b,c,p))
        std::cout << "inside" << std::endl;
    else
        std::cout << "outside" << std::endl;
    return (0);
}