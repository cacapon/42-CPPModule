/**
 * @file bsp.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed cross(Point const& a, Point const& b, Point const& point) {
    Fixed abx = b.getX() - a.getX();
    Fixed aby = b.getY() - a.getY();
    Fixed apx = point.getX() - a.getX();
    Fixed apy = point.getY() - a.getY();
    return (abx * apy - aby * apx);
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
    Fixed c1 = cross(a, b, point);
    Fixed c2 = cross(b, c, point);
    Fixed c3 = cross(c, a, point);

    if (c1 == Fixed(0) || c2 == Fixed(0) || c3 == Fixed(0)) return (false);
    bool allPositive = (c1 > Fixed(0) && c2 > Fixed(0) && c3 > Fixed(0));
    bool allNegative = (c1 < Fixed(0) && c2 < Fixed(0) && c3 < Fixed(0));

    return allPositive || allNegative;
}