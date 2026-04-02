/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:02 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/02 04:33:26 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << GREEN << "Default constructor Cat called" << RESET << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << GREEN << "Copy constructor Cat called" << RESET << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << MAGENTA << "Copy assignment operator Cat called" << RESET << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = other.brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << RED << "Destructor Cat called" << RESET << std::endl;
	delete brain;
}

void	Cat::makeSound() const
{
	std::cout << CYAN << "Miaw" << RESET << std::endl;
}

void	Cat::setIdea(const std::string &idea)
{
	if (this->brain)
		this->brain->setIdea(idea);
}

std::ostream &operator<<(std::ostream &os, const Cat &cat)
{
	os << "Type: " << cat.type << std::endl;
	if (cat.brain)
		os << *(cat.brain);
	return os;
}