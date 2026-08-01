/**
 * @file Span.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-07-28
 *
 *
 */

#pragma once

#include <sys/types.h>

#include <vector>
class Span {
   private:
    unsigned int _size;
    std::vector<int> _container;
    Span();

   public:
    class FullException : public std::exception {
       public:
        virtual const char* what() const throw();
    };
    class NoSpanException : public std::exception {
       public:
        virtual const char* what() const throw();
    };

    Span(unsigned int);
    Span(const Span&);
    Span& operator=(const Span&);
    ~Span();

    void addNumber(int);
    template <typename InputIterator>
    void addNumber(InputIterator begin, InputIterator end);
    unsigned int longestSpan();
    unsigned int shortestSpan();
};

template <typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end) {
    for (InputIterator i = begin; i != end; ++i) {
        addNumber(*i);
    }
}
