/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include "Base.hpp"
#include "baseUtils.hpp"

int main() {
    Base* p = generate();
    identify(p);
    identify(*p);
    delete p;
    return 0;
}