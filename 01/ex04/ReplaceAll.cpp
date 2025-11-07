/**
 * @file ReplaceAll.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief Replace a string contained within a single line of text
 * 
 * 
 */

#include "ReplaceAll.hpp"

std::string replace_all(
    const std::string &src,
    const std::string &from,
    const std::string &to)
{
    std::string             result;
    std::string::size_type  pos;
    std::string::size_type  found;

    pos = 0;
    while ((found = src.find(from, pos)) != std::string::npos)
    {
        result.append(src, pos, found - pos);
        result.append(to);
        pos = found + from.length();
    }
    result.append(src, pos, src.length() - pos);
    return (result);
};
