/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:25:37 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/24 02:17:13 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN << "Default constructor FragTrap called" << RESET << std::endl;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << GREEN << "Copy constructor FragTrap called" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED << "Destructor FragTrap called" << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << MAGENTA << "Copy assignment operator FragTrap called" << RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		Attack_damage = other.Attack_damage;
		Energy_points = other.Energy_points;
		Hit_points = other.Hit_points;
	}
	return *this;
}

FragTrap::FragTrap(const std::string _name) : ClapTrap()
{
	std::cout << GREEN << _name << " constructor FragTrap called" << RESET << std::endl;
	name = _name;
	Hit_points = 100;
	Energy_points = 50;
	Attack_damage = 20;
}

void	FragTrap::attack(const std::string& target)
{
	if (Energy_points && Hit_points)
	{
		Energy_points--;
		std::cout << YELLOW << "FragTrap " << name <<" attacks " << target << ", causing " << Attack_damage << " points of damage!" << RESET << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << BLUE << "FragTrap " << name << " - high-fiving guys!" << RESET << std::endl;
}