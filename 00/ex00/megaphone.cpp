/**
 * @file megaphone.cpp
 * @brief Get familiar with C++ syntax.
 */

#include <iostream>
#include <string>

/**
 * @brief Output strs in uppercase to the console.
 *
 * If no specification is given, the default character is output.
 *
 * @param strs
 */
static void	local_megaphone(char **strs)
{
	int				strs_i;
	int 			str_i;
	unsigned char	uc;

	if (strs == NULL)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return ;
	}
	strs_i = 1;
	while (strs[strs_i])
	{
		str_i = 0;
		while(strs[strs_i][str_i] != '\0')
		{
			uc = std::toupper(strs[strs_i][str_i++]);
			std::cout << uc;
		}
		strs_i++;
	}
	std::cout << "\n";
}

int	main(int ac, char **av)
{
	if (ac == 1)
		local_megaphone(NULL);
	else
		local_megaphone(av);
	return (0);
}
