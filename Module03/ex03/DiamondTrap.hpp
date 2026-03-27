/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:36:19 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/27 00:55:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	using 	ScavTrap::attack;

							DiamondTrap();
							DiamondTrap(const DiamondTrap &other);
	DiamondTrap				&operator=(const DiamondTrap &other);
							~DiamondTrap();
							DiamondTrap(std::string name);
	void					whoAmI();
	friend std::ostream&	operator<<(std::ostream& os, const DiamondTrap& dt);
private:
	std::string name;
};

#endif 