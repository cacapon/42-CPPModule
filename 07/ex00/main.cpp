/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>

#include "whatever.hpp"

#ifdef TEST
class Number {
   public:
    int value;
    Number(int v) : value(v) {}

    bool operator<(const Number& other) const { return value < other.value; }
    bool operator>(const Number& other) const { return value > other.value; }
};

class NoCompare {
   public:
    int v;
    NoCompare(int x) : v(x) {}
};

std::ostream& operator<<(std::ostream& os, const Number& n) {
    os << n.value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const NoCompare& n) {
    os << n.v;
    return os;
}

static void custom_class_compare_test() {
    std::cout << "[custom class compare test]" << std::endl;
    Number n1(2);
    Number n2(5);

    std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
    std::cout << "min( n1, n2 ) = " << ::min(n1, n2) << std::endl;
    std::cout << "max( n1, n2 ) = " << ::max(n1, n2) << std::endl;
    std::cout << std::endl;
}

// Uncommenting this line will cause a compilation error.
static void compile_error_test() {
    std::cout << "[compile error test]" << std::endl;
    NoCompare n1(2);
    NoCompare n2(5);

    std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
    // NoCompare mn(::min(n1, n2));  // compile error
    // NoCompare mx(::max(n1, n2));  // compile error
    // std::cout << "min( n1, n2 ) = " << mn << std::endl;
    // std::cout << "max( n1, n2 ) = " << mx << std::endl;
    std::cout << std::endl;
}

#endif  // TEST

static void basic_test() {
    std::cout << "[basic test]" << std::endl;
    {
        int i1 = 2, i2 = 3;

        std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
        std::cout << "swap( i1, i2 )" << std::endl;
        ::swap(i1, i2);
        std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
        std::cout << "min( i1, i2 ) = " << ::min(i1, i2) << std::endl;
        std::cout << "max( i1, i2 ) = " << ::max(i1, i2) << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s1 = "taro";
        std::string s2 = "saburo";

        std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
        std::cout << "swap( s1, s2 )" << std::endl;
        ::swap(s1, s2);
        std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
        std::cout << "min( s1, s2 ) = " << ::min(s1, s2) << std::endl;
        std::cout << "max( s1, s2 ) = " << ::max(s1, s2) << std::endl;
        std::cout << std::endl;
    }
    {
        char c1 = 'a', c2 = 'z';
        std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
        std::cout << "swap( c1, c2 )" << std::endl;
        ::swap(c1, c2);
        std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
        std::cout << "min( c1, c2 ) = " << ::min(c1, c2) << std::endl;
        std::cout << "max( c1, c2 ) = " << ::max(c1, c2) << std::endl;
        std::cout << std::endl;
    }
}

int main() {
    basic_test();
#ifdef TEST
    custom_class_compare_test();
    compile_error_test();
#endif  // TEST
    return 0;
}