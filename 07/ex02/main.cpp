/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#include <iostream>

#include "Array.hpp"

static void test_array_int() {
    Array<int> arr(3);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    std::cout << "[" << arr[0] << ", " << arr[1] << ", " << arr[2] << "]"
              << std::endl;
}

static void test_array_char() {
    Array<char> arr(5);
    arr[0] = 'h';
    arr[1] = 'e';
    arr[2] = 'l';
    arr[3] = 'l';
    arr[4] = 'o';
    std::cout << "['" << arr[0] << "', '" << arr[1] << "', '" << arr[2]
              << "', '" << arr[3] << "', '" << arr[4] << "']" << std::endl;
}

static void test_array_str() {
    Array<std::string> arr(2);
    arr[0] = "welcome";
    arr[1] = "i-freek mobile!";
    std::cout << "[\"" << arr[0] << "\", \"" << arr[1] << "\"]" << std::endl;
}

static void test_array_float() {
    Array<float> arr(4);
    arr[0] = 1.2f;
    arr[1] = 3.456f;
    arr[2] = 78.901f;
    arr[3] = 2.345678890f;
    std::cout << "[" << arr[0] << "f, " << arr[1] << "f, " << arr[2] << "f, "
              << arr[3] << "f]" << std::endl;
}

static void test_array_double() {
    Array<double> arr(4);
    arr[0] = 1.2;
    arr[1] = 3.456;
    arr[2] = 78.901;
    arr[3] = 2.345678890;
    std::cout << "[" << arr[0] << ", " << arr[1] << ", " << arr[2] << ", "
              << arr[3] << "]" << std::endl;
}

static void test_exception() {
    Array<int> arr(0);
    try {
        arr[0] = 1;
    } catch (std::exception &e) {
        std::cout << "Error:" << e.what() << std::endl;
    }
}

static void test_exception_const() {
    const Array<int> arr(1);
    try {
        std::cout << arr[3] << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error:" << e.what() << std::endl;
    }
}

int main() {
    test_array_int();
    test_array_char();
    test_array_str();
    test_array_float();
    test_array_double();
    test_exception();
    test_exception_const();
    return 0;
}