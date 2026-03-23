/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:16:28 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/23 02:49:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	name = "noname";
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	name = other.name;
	Attack_damage = other.Attack_damage;
	Energy_points = other.Energy_points;
	Hit_points = other.Hit_points;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		Attack_damage = other.Attack_damage;
		Energy_points = other.Energy_points;
		Hit_points = other.Hit_points;
	}
	return *this;
}

ClapTrap::ClapTrap(const std::string _name)
{
	std::cout << GREEN << _name << " constructor called" << RESET << std::endl;
	name = _name;
	Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
}

void	ClapTrap::attack(const std::string& target)
{
	if (Energy_points && Hit_points)
	{
		Energy_points--;
		std::cout << YELLOW << "ClapTrap " << name <<" attacks " << target << ", causing " << Attack_damage << " points of damage!" << RESET << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << MAGENTA << "ClapTrap " << name <<" take damage, received " << amount << " points of damage!" << RESET << std::endl;
	Hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Energy_points && Hit_points)
	{
		std::cout << CYAN << "ClapTrap " << name <<" be repaired, recover " << amount << " health points!" << RESET << std::endl;
		Energy_points--;
		Hit_points += amount;
	}
}