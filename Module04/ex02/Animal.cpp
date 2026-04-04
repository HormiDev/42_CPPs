/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:00:13 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/30 02:05:31 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << GREEN << "Default constructor Animal called" << RESET << std::endl;
	type = "type";
}

Animal::Animal(const Animal &other)
{
	std::cout << GREEN << "Copy constructor Animal called" << RESET << std::endl;
	type = other.type;
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << MAGENTA << "Copy assignment operator Animal called" << RESET << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << RED << "Destructor Animal called" << RESET << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << CYAN << "..." << RESET << std::endl;
}

std::string	Animal::getType() const
{
	return type;
}