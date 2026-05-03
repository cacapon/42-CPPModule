/**
 * @file Array.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 *
 *
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <exception>

template <typename T>
class Array {
   public:
    /* ctor and dtor */
    Array();
    Array(unsigned int n);
    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    ~Array();
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

   public:
    unsigned int size() const;

   private:
    T* _data;
    unsigned int _size;
};

#include "Array.tpp"
#endif