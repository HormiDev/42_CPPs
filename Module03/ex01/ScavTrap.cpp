/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:25:37 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/24 01:53:50 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GREEN << "Default constructor ScavTrap called" << RESET << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << GREEN << "Copy constructor ScavTrap called" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << "Destructor ScavTrap called" << RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << MAGENTA << "Copy assignment operator ScavTrap called" << RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		Attack_damage = other.Attack_damage;
		Energy_points = other.Energy_points;
		Hit_points = other.Hit_points;
	}
	return *this;
}

ScavTrap::ScavTrap(const std::string _name) : ClapTrap()
{
	std::cout << GREEN << _name << " constructor ScavTrap called" << RESET << std::endl;
	name = _name;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

void	ScavTrap::attack(const std::string& target)
{
	if (Energy_points && Hit_points)
	{
		Energy_points--;
		std::cout << YELLOW << "ScavTrap " << name <<" attacks " << target << ", causing " << Attack_damage << " points of damage!" << RESET << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap " << name << " is now guarding the gate!" << RESET << std::endl;
}