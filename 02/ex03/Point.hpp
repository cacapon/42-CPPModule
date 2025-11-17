/**
 * @file Point.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
  public:
    Point();
    Point(const float x, const float y);
    Point(const Point &other);
    Point& operator=(const Point &other);
    ~Point();
    Fixed getX() const;
    Fixed getY() const;

  private:
    Fixed const x;
    Fixed const y;
};

bool bsp(Point const& a, Point const& b, Point const& c, Point const& point);

#endif