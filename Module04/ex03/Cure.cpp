/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:19:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/13 14:38:01 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Default constructor Cure called" << RESET << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << GREEN << "Copy constructor Cure called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	std::cout << MAGENTA << "Assignment operator Cure called" << RESET << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cout << RED << "Destructor Cure called" << RESET << std::endl;
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << YELLOW << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}