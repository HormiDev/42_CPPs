/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:37:13 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/13 14:37:46 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN << "Default constructor Ice called" << RESET << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << GREEN << "Copy constructor Ice called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	std::cout << MAGENTA << "Assignment operator Ice called" << RESET << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << RED << "Destructor Ice called" << RESET << std::endl;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << CYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}