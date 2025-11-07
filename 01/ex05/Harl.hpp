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
    private:
        int     getCmd(const std::string level);
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        void    default_msg(void);
};

#endif
