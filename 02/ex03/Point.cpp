/**
 * @file Point.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}
Point::Point(const float x, const float y) : x(Fixed(x)), y(Fixed(y)) {}
Point::Point(const Point &other) : x(Fixed(other.x)), y(Fixed(other.y)) {}
Point &Point::operator=(const Point &other) {
    (void)other;
    return *this;
}
Point::~Point() {}

Fixed Point::getX() const { return this->x; }
Fixed Point::getY() const { return this->y; }