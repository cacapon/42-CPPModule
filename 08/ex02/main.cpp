/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-01
 *
 *
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>

#include "MutantStack.hpp"

static void test_output(const std::string& title, bool result) {
    std::cout << title;
    if (result)
        std::cout << ":OK";
    else
        std::cout << ":NG";
    std::cout << std::endl;
}

static void normal_test() {
    MutantStack<int> ms;
    std::list<int> ls;
    int arr[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        ms.push(arr[i]);
        ls.push_back(arr[i]);
    }
    bool result = std::equal(ms.begin(), ms.end(), ls.begin());
    test_output("normal_test", result);
}

static void empty_test() {
    MutantStack<int> ms;
    bool result = (ms.begin() == ms.end());
    test_output("empty_test", result);
}

static void one_test() {
    MutantStack<int> ms;
    std::list<int> ls;
    int arr[] = {1};
    ms.push(arr[0]);
    ls.push_back(arr[0]);
    bool result = std::equal(ms.begin(), ms.end(), ls.begin());
    test_output("one_test", result);
}

static void copy_test() {
    MutantStack<int> ms_org;
    int arr[] = {1, 2, 3};
    for (int i = 0; i < 3; i++) {
        ms_org.push(arr[i]);
    }
    MutantStack<int> ms_cp(ms_org);
    MutantStack<int> ms_ope;
    ms_ope = ms_org;

    bool result1 = std::equal(ms_org.begin(), ms_org.end(), ms_cp.begin());
    test_output("copy_test::copy", result1);
    bool result2 = std::equal(ms_org.begin(), ms_org.end(), ms_ope.begin());
    test_output("copy_test::operator", result2);
}

static void subject_test() {
    std::cout << "subject_test:start" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "subject_test:end" << std::endl;
}

int main() {
    normal_test();
    empty_test();
    one_test();
    copy_test();
    subject_test();
    return 0;
}
