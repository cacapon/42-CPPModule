/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-07-28
 *
 *
 */

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Span.hpp"

template <typename T>
static bool ft_assert_eq(T a, T b) {
    return a == b;
}

static void test_output(const std::string& title, bool result) {
    std::cout << title;
    if (result)
        std::cout << ":OK";
    else
        std::cout << ":NG";
    std::cout << std::endl;
}

static void normal_test() {
    Span sp = Span(5);
    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(4);
        sp.addNumber(8);
        test_output("normal_test::addnumber", true);
    } catch (Span::FullException&) {
        test_output("normal_test::addnumber", false);
        return;
    }
    test_output("normal_test::short", sp.shortestSpan() == 1);
    test_output("normal_test::long", sp.longestSpan() == 7);
}

static void error_test() {
    Span sp = Span(3);
    try {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(4);
        sp.addNumber(8);
        test_output("error_test::addnumber", false);
    } catch (Span::FullException&) {
        test_output("error_test::addnumber", true);
    }
    Span sp2 = Span(3);
    try {
        sp2.addNumber(1);
        sp2.shortestSpan();
        test_output("error_test::short", false);
    } catch (Span::NoSpanException&) {
        test_output("error_test::short", true);
    }
    Span sp3 = Span(3);
    try {
        sp3.addNumber(1);
        sp3.longestSpan();
        test_output("error_test::long", false);
    } catch (Span::NoSpanException&) {
        test_output("error_test::long", true);
    }
}

static void limit_test() {
    Span sp = Span(0);
    try {
        sp.addNumber(1);
        test_output("limit_test::N=0", false);
    } catch (Span::FullException&) {
        test_output("limit_test::N=0", true);
    }
    Span sp2 = Span(1);
    try {
        sp2.addNumber(1);
        test_output("limit_test::N=1", true);
    } catch (Span::FullException&) {
        test_output("limit_test::N=1", false);
    }
    Span sp3 = Span(3);
    try {
        sp3.addNumber(5);
        sp3.addNumber(5);
        sp3.addNumber(5);
        test_output("limit_test::short([5,5,5])", sp3.shortestSpan() == 0);
        test_output("limit_test::long([5,5,5])", sp3.longestSpan() == 0);
    } catch (Span::FullException&) {
        test_output("limit_test::addNumber(5)x3 failed", false);
    } catch (Span::NoSpanException&) {
        test_output("limit_test::[short|long]estSpan() failed", false);
    }
}

static void large_test() {
    unsigned int n = 10000;
    std::vector<int> vec;
    for (unsigned int i = 0; i < n; i++) vec.push_back(std::rand());
    Span sp = Span(n);
    sp.addNumber(vec.begin(), vec.end());

    int mn = *std::min_element(vec.begin(), vec.end());
    int mx = *std::max_element(vec.begin(), vec.end());
    unsigned int expected_longest = mx - mn;
    test_output("large_test::longest", sp.longestSpan() == expected_longest);

    unsigned int expected_shortest = UINT_MAX;
    for (unsigned int i = 0; i < vec.size(); i++) {
        for (size_t j = i + 1; j < vec.size(); j++) {
            unsigned int diff = std::abs(vec[i] - vec[j]);
            if (diff < expected_shortest) expected_shortest = diff;
        }
    }
    test_output("large_test::shortest", sp.shortestSpan() == expected_shortest);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    normal_test();
    error_test();
    limit_test();
    large_test();
    return 0;
}
