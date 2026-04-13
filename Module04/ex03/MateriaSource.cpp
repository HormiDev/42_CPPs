/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 03:56:19 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/13 16:19:08 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << GREEN << "MateriaSource default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	std::cout << GREEN << "MateriaSource copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		materia[i] = other.materia[i];
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other)
{
	std::cout << MAGENTA << "MateriaSource assignment operator called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
		materia[i] = other.materia[i];
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << RED << "MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (materia[i] == m)
		{
			std::cout << YELLOW << "MateriaSource already knows this exact instance" << RESET << std::endl;
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!materia[i])
		{
			std::cout << CYAN << "MateriaSource learned a new materia" << m->getType() << RESET << std::endl;
			materia[i] = m;
			return;
		}
	}
	std::cout << YELLOW << "MateriaSource cannot learn more than 4 materia" << RESET << std::endl;
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	AMateria *tmp = NULL;

	for (int i = 0; i < 4; i++)
	{
		if (materia[i] && materia[i]->getType() == type)
		{
			tmp = materia[i]->clone();
			return tmp;
		}
	}
	std::cout << YELLOW << "MateriaSource does not have a materia of type " << type << RESET << std::endl;
	return NULL;
}

std::ostream	&operator<<(std::ostream &out, const MateriaSource &materia)
{
	out << "MateriaSource: {";
	for (int i = 0; i < 4; i++)
	{
		if (materia.materia[i])
			out << materia.materia[i]->getType() << ", ";
		else
			out << "NULL, ";
	}
	out << "}" << std::endl;
	return out;
}