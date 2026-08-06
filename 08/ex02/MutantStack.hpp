/**
 * @file MutantStack.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-01
 *
 *
 */

#pragma once
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
   public:
    MutantStack();
    MutantStack(const MutantStack&);
    MutantStack& operator=(const MutantStack&);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"
