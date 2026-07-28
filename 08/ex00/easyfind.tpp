/**
 * @file easyfind.tpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-07-28
 *
 *
 */

#pragma once
#include <algorithm>
#include <iterator>

const char* IteratorNotFound::what() const throw() {
    return "Iterator not found.";
}

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it =
        std::find(container.begin(), container.end(), value);
    if (it == container.end()) throw IteratorNotFound();
    return (it);
}
