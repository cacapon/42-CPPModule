/**
 * @file open_input.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#ifndef OPEN_INPUT_HPP
# define OPEN_INPUT_HPP
# include <fstream>
# include <iostream>

bool    open_input(std::ifstream &input, const char *fname);
bool    open_output(std::ofstream &output, const char *fname);

#endif