/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 02:33:25 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/13 16:37:38 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << GREEN << "Default constructor Character called" << RESET << std::endl;
	name = "noname";
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name)
{
	std::cout << GREEN << "Copy constructor Character called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = other.inventory[i];
}

Character	&Character::operator=(const Character& other)
{
	std::cout << MAGENTA << "Assignment operator Character called" << RESET << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			inventory[i] = other.inventory[i];
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << RED << "Destructor Character called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

Character::Character(std::string const &name) : name(name)
{
	std::cout << GREEN << "Parameterized constructor Character called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		inventory[i] = 0;
}

std::string	const	&Character::getName() const
{
	return name;
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == m)
		{
			std::cout << YELLOW << "Materia already equipped!" << RESET << std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << CYAN << "Materia " << m->getType() << " equipped!" << RESET << std::endl;
			return ;
		}
	}
	std::cout << YELLOW << "Inventory is full!" << RESET << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (inventory[idx])
		{
			std::cout << MAGENTA << "Materia " << inventory[idx]->getType() << " unequipped!" << RESET << std::endl;
			inventory[idx] = 0;
			return ;
		}
		else
		{
			std::cout << YELLOW << "No materia equipped in slot " << idx << "!" << RESET << std::endl;
			return ;
		}
	}
	std::cout << YELLOW << "Invalid slot index!" << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4)
	{
		if (inventory[idx])
		{
			inventory[idx]->use(target);
			return ;
		}
		else
		{
			std::cout << YELLOW << "No materia equipped in slot " << idx << "!" << RESET << std::endl;
			return ;
		}
	}
	std::cout << YELLOW << "Invalid slot index!" << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &out, const Character &character)
{
	out << "Character: " << character.name << " {" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (character.inventory[i])
			out << character.inventory[i]->getType() << ", " << std::endl;
		else
			out << "NULL, " << std::endl;
	}
	out << "}" << std::endl;
	return out;
}