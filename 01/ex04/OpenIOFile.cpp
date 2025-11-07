/**
 * @file OpenIOFile.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 * 
 */

#include "OpenIOFile.hpp"

static  void    print_cannot_open(const char *fname)
{
    std::cerr << "Error: cannot open " << fname << std::endl;
}

bool    open_input(std::ifstream &input, const char *fname)
{
    input.open(fname);
    if (!input)
        return (print_cannot_open(fname), false);
    return (true);
}
bool    open_output(std::ofstream &output, const char *fname)
{
    std::string outfile = std::string(fname) + ".replace";

    output.open(outfile.c_str());
    if (!output)
        return (print_cannot_open(fname), false);
    return (true);
}
