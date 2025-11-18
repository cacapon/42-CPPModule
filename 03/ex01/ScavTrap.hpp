/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:32:57 by ttsubo            #+#    #+#             */
/*   Updated: 2025/11/18 07:02:12 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();
        void guardGate();
    private:
        virtual void showName() const;      
};

#endif