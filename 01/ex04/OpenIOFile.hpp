/**
 * @file OpenIOFile.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#ifndef OPENIOFILE_HPP
# define OPENIOFILE_HPP
# include <fstream>
# include <iostream>

bool    open_input(std::ifstream &input, const char *fname);
bool    open_output(std::ofstream &output, const char *fname);

#endif