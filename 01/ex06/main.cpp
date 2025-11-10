/**
 * @file main.cpp
 * @author ttsubo (ttsubo@student.42.fr)
 * @brief 
 * 
 */

#include "Harl.hpp"
#include <iostream>

void	usage(void)
{
	std::cout << "Usage: ./harlFilter <LOG Level>" << std::endl;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (usage(), 1);

	Harl*   harl = new Harl();
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int loglevel = harl->getCmd(av[1]);

	if (loglevel == -1)
		harl->complain("default");
	else
	{
		for (int i=loglevel; i<4; i++)
		{
			std::cout << "[ " << levels[i] << " ]" << std::endl;
			harl->complain(levels[i]);
			std::cout << std::endl;
		}
	}

	delete harl;
    return (0);
}