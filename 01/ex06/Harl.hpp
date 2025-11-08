/**
 * @file Harl.hpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief Bacon-loving complainer
 * 
 * 
 */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>

class Harl
{
    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);
        int     getCmd(const std::string level);
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        void    default_msg(void);
};

#endif
