/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:57:03 by ttsubo            #+#    #+#             */
/*   Updated: 2025/12/17 08:14:19 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "easyfind.hpp"
#define RUN_TEST(fn) test(#fn, fn)

static void test_deque() {
    std::deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    try {
        std::cout << easyfind(dq, 10) << std::endl;
        std::cout << easyfind(dq, 20) << std::endl;
        std::cout << easyfind(dq, 30) << std::endl;
        std::cout << easyfind(dq, 42) << std::endl;
    } catch (...) {
        std::cout << "not found" << std::endl;
    }
}

static void test_list() {
    std::list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try {
        std::cout << easyfind(l, 10) << std::endl;
        std::cout << easyfind(l, 20) << std::endl;
        std::cout << easyfind(l, 30) << std::endl;
        std::cout << easyfind(l, 42) << std::endl;
    } catch (...) {
        std::cout << "not found" << std::endl;
    }
}

static void test_vector() {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    try {
        std::cout << easyfind(v, 10) << std::endl;
        std::cout << easyfind(v, 20) << std::endl;
        std::cout << easyfind(v, 30) << std::endl;
        std::cout << easyfind(v, 42) << std::endl;
    } catch (...) {
        std::cout << "not found" << std::endl;
    }
}

static void test_const_vector() {
    int arr[] = {10, 20, 30};
    const std::vector<int> cv(arr, arr + 3);

    try {
        std::cout << easyfind(cv, 10) << std::endl;
        std::cout << easyfind(cv, 20) << std::endl;
        std::cout << easyfind(cv, 30) << std::endl;
        std::cout << easyfind(cv, 42) << std::endl;
    } catch (...) {
        std::cout << "not found" << std::endl;
    }
}

static void test_empty_vector() {
    std::vector<int> v;

    try {
        std::cout << easyfind(v, 42) << std::endl;
    } catch (...) {
        std::cout << "not found" << std::endl;
    }
}

static void test(std::string test_name, void (*test)(void)) {
    std::cout << "<" << test_name << "_start>" << std::endl;
    test();
    std::cout << "<" << test_name << "_end>" << std::endl;
    std::cout << std::endl;
}

int main() {
    RUN_TEST(test_deque);
    RUN_TEST(test_list);
    RUN_TEST(test_vector);
    RUN_TEST(test_const_vector);
    RUN_TEST(test_empty_vector);
    return 0;
}