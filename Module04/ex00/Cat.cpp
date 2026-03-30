/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:02 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/30 02:06:51 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Default constructor Cat called" << RESET << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << GREEN << "Copy constructor Cat called" << RESET << std::endl;
	type = other.type;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << MAGENTA << "Copy assignment operator Cat called" << RESET << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << RED << "Destructor Cat called" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << CYAN << "Miaw" << RESET << std::endl;
}