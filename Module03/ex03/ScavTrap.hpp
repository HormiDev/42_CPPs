/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:25:41 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/26 13:55:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
					ScavTrap();
					ScavTrap(const ScavTrap &other);
		ScavTrap	&operator=(const ScavTrap &other);
					~ScavTrap();
					ScavTrap(std::string name);
		void		attack(const std::string& target);
		void		guardGate();
};

#endif