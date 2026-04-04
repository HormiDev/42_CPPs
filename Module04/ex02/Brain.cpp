/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 03:17:30 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/02 04:20:27 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Default constructor Brain called" << RESET << std::endl;
	idea_iterator = 0;
}

Brain::~Brain()
{
	std::cout << RED << "Destructor Brain called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << YELLOW << "Copy constructor Brain called" << RESET << std::endl;
	*this = other;
	idea_iterator = other.idea_iterator;
}
Brain &Brain::operator=(const Brain &other)
{
	std::cout << MAGENTA << "Assignment operator Brain called" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	idea_iterator = other.idea_iterator;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Brain &brain)
{
	int i = 0;

	while (i < 100)
	{
		if (brain.ideas[i] != "")
		os << "[" << i << "]: " << YELLOW << brain.ideas[i] << RESET << std::endl;
		i++;
	}
	return os;
}

void Brain::setIdea(const std::string &idea)
{
	ideas[idea_iterator] = idea;
	idea_iterator++;
	if (idea_iterator >= 100)
		idea_iterator = 0;
}