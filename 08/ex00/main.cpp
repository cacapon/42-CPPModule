/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-07-28
 *
 *
 */

#include <climits>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

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

static void normal_test1() {
    int arr[] = {1, 1, 2, 2, 3, 3};
    std::vector<int> vec(arr, arr + 6);
    std::vector<int>::iterator it = easyfind(vec, 2);
    test_output("normal_test1", ft_assert_eq(vec.begin() + 2, it));
}

static void normal_test2() {
    int arr[] = {2};
    std::vector<int> vec(arr, arr + 1);
    std::vector<int>::iterator it = easyfind(vec, 2);
    test_output("normal_test2", ft_assert_eq(vec.begin(), it));
}

static void error_test1() {
    int arr[] = {1, 2, 3};
    std::vector<int> vec(arr, arr + 3);
    try {
        easyfind(vec, 4);
        test_output("error_test1", false);
    } catch (IteratorNotFound& e) {
        test_output("error_test1", true);
    }
}

static void error_test2() {
    std::vector<int> vec;
    try {
        easyfind(vec, 1);
        test_output("error_test2", false);
    } catch (IteratorNotFound& e) {
        test_output("error_test2", true);
    }
}

static void limit_test1() {
    int arr[] = {INT_MIN, 0, INT_MAX};
    std::vector<int> vec(arr, arr + 3);
    std::vector<int>::iterator it = easyfind(vec, INT_MIN);
    test_output("limit_test1", ft_assert_eq(vec.begin(), it));
}

static void limit_test2() {
    int arr[] = {INT_MIN, 0, INT_MAX};
    std::vector<int> vec(arr, arr + 3);
    std::vector<int>::iterator it = easyfind(vec, INT_MAX);
    test_output("limit_test2", ft_assert_eq(vec.begin() + 2, it));
}

static void large_test() {
    std::vector<int> vec;
    for (int i = 0; i < 100000; i++) vec.push_back(i);
    std::vector<int>::iterator it = easyfind(vec, 90000);
    test_output("large_test", ft_assert_eq(vec.begin() + 90000, it));
}

static void list_test() {
    int arr[] = {1, 1, 2, 2, 3, 3};
    std::list<int> list(arr, arr + 6);
    std::list<int>::iterator expected = list.begin();
    std::advance(expected, 4);
    test_output("list_test", ft_assert_eq(expected, easyfind(list, 3)));
}

int main() {
    normal_test1();
    normal_test2();
    error_test1();
    error_test2();
    limit_test1();
    limit_test2();
    large_test();
    list_test();
    return 0;
}
