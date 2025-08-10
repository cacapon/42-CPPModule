/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:04:40 by ttsubo            #+#    #+#             */
/*   Updated: 2025/08/10 11:16:52 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <algorithm>

/**
 * @brief Output strs in uppercase to the console.
 * 
 * If no specification is given, the default character is output.
 * 
 * @param strs 
 */
static void	local_megaphone(char **strs)
{
	if (strs == NULL)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return ;
	}
	int i = 1;
	while (strs[i])
	{
		std::string s = strs[i++];
		std::transform(s.begin(), s.end(), s.begin(),
			static_cast<int(*)(int)>(std::toupper));
		std::cout << s;
	}
	std::cout << "\n";
}

int main(int ac, char **av)
{
	if (ac == 1)
		local_megaphone(NULL);
	else
		local_megaphone(av);
	return (0);
}
