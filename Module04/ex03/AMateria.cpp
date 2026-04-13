/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 12:31:52 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/13 02:44:41 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("")
{
	std::cout << GREEN << "Default constructor AMateria called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria &other) : type(other.type)
{
	std::cout << GREEN << "Copy constructor AMateria called" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << MAGENTA << "Assignment operator AMateria called" << RESET << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << RED << "Destructor AMateria called" << RESET << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << GREEN << "Parameterized constructor AMateria called" << RESET << std::endl;
}

std::string const	&AMateria::getType() const
{
	return type;
}