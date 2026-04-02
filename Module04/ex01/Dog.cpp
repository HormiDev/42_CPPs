/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:02 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/02 04:35:22 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << GREEN << "Default constructor Dog called" << RESET << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << GREEN << "Copy constructor Dog called" << RESET << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << MAGENTA << "Copy assignment operator Dog called" << RESET << std::endl;
	if (this != &other)
	{
		type = other.type;
		brain = other.brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << RED << "Destructor Dog called" << RESET << std::endl;
	delete brain;
}

void	Dog::makeSound() const
{
	std::cout << CYAN << "Guau" << RESET << std::endl;
}

void	Dog::setIdea(const std::string &idea)
{
	if (this->brain)
		this->brain->setIdea(idea);
}

std::ostream &operator<<(std::ostream &os, const Dog &dog)
{
	os << "Type: " << dog.type << std::endl;
	if (dog.brain)
		os << *(dog.brain);
	return os;
}