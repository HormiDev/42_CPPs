/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 00:36:06 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/27 00:58:34 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap()
{
	std::cout << GREEN << "Default constructor DiamondTrap called" << RESET << std::endl;
	name = "noname";
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << GREEN << "Copy constructor DiamondTrap called" << RESET << std::endl;
	name = other.name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "Destructor DiamondTrap called" << RESET << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << MAGENTA << "Copy assignment operator DiamondTrap called" << RESET << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		name = other.name;
		Attack_damage = other.Attack_damage;
		Energy_points = other.Energy_points;
		Hit_points = other.Hit_points;
	}
	return *this;
}

DiamondTrap::DiamondTrap(const std::string _name) : ScavTrap(_name), FragTrap(_name)
{
	std::cout << GREEN << _name << " constructor DiamondTrap called" << RESET << std::endl;
	name = _name;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 30;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am " << name << ", a DiamondTrap! and my ClapTrap name is " << ClapTrap::name << std::endl;
}

std::ostream& operator<<(std::ostream &os, const DiamondTrap &dt)
{
	os << "[ " << dt.name << " ]{ HP: " << dt.Hit_points << ", EP: " << dt.Energy_points << ", AD: " << dt.Attack_damage << " }" << std::endl;
	return os;
}