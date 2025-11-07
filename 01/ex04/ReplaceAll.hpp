/**
 * @file ReplaceAll.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief Replace a string contained within a single line of text
 * 
 * 
 */

#ifndef REPLACEALL_HPP
# define REPLACEALL_HPP
# include <string>

std::string replace_all(
    const std::string &src,
    const std::string &from,
    const std::string &to);

#endif