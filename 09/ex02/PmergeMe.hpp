/**
 * @file PmergeMe.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief
 * @date 2026-08-09
 *
 *
 */

#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <exception>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::list<int> _lst;
    void _parseInput(int argc, char** argv);
    std::vector<int> _getInsertionOrder(size_t n);
    std::vector<int> _sortVector(std::vector<int> input);
    std::list<int> _sortList(std::list<int> input);
    template <typename Container>
    void _printContainer(const std::string& label, const Container& c);

public:
    class PmergeMeError : public std::exception {
    public:
        PmergeMeError();
        PmergeMeError(const std::string& detail);
        PmergeMeError(const PmergeMeError& other);
        PmergeMeError& operator=(const PmergeMeError& other);
        ~PmergeMeError() throw();

        const char* what() const throw();

    private:
        std::string _detail;
    };
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    void run(int argc, char** argv);
};

template <typename Container>
void PmergeMe::_printContainer(const std::string& label, const Container& c) {
    std::cout << label;
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
#endif
