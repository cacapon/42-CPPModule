/**
 * @file easyfind.hpp
 * @author cacapon (cacapon.project@gmail.com)
 * @brief
 * @date 2026-07-28
 *
 *
 */

#pragma once
#include <exception>

class IteratorNotFound : public std::exception {
   public:
    virtual const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"
