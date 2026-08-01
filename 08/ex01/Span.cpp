/**
 * @file Span.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-07-28
 *
 *
 */

#include "Span.hpp"

#include <algorithm>
#include <climits>
#include <exception>

const char* Span::FullException::what() const throw() {
    return "FullException::Container is full.";
}

const char* Span::NoSpanException::what() const throw() {
    return "NoSpanException::No span.";
}

Span::Span(unsigned int n) : _size(n) {}
Span::Span(const Span& other)
    : _size(other._size), _container(other._container) {}
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _size = other._size;
        _container = other._container;
    }
    return *this;
}
Span::~Span() {}

void Span::addNumber(int n) {
    if (_container.size() >= _size) throw FullException();
    _container.push_back(n);
}

unsigned int Span::longestSpan() {
    if (_container.size() < 2) throw NoSpanException();
    std::sort(_container.begin(), _container.end());
    return _container[_container.size() - 1] - _container[0];
}

unsigned int Span::shortestSpan() {
    if (_container.size() < 2) throw NoSpanException();

    unsigned int shortest_distance = UINT_MAX;
    std::sort(_container.begin(), _container.end());
    for (unsigned int i = 0; i + 1 < _container.size(); i++) {
        unsigned int distance = _container[i + 1] - _container[i];
        if (distance < shortest_distance) shortest_distance = distance;
        if (shortest_distance == 0) return shortest_distance;
    }
    return shortest_distance;
}
