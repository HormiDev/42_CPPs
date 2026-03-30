/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:02 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/30 02:05:18 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << GREEN << "Default constructor Dog called" << RESET << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << GREEN << "Copy constructor Dog called" << RESET << std::endl;
	type = other.type;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << MAGENTA << "Copy assignment operator Dog called" << RESET << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << RED << "Destructor Dog called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << CYAN << "Guau" << RESET << std::endl;
}