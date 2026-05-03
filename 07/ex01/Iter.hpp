/**
 * @file iter.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *arr, size_t n, void (*f)(T &)) {
    for (size_t i = 0; i < n; i++) f(arr[i]);
}

template <typename T>
void iter(const T *arr, const size_t n, void (*f)(T const &)) {
    for (size_t i = 0; i < n; i++) f(arr[i]);
}

#endif