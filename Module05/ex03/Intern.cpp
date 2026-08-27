/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:40:34 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/28 00:55:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) 
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other) 
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string target) const 
{
	FormCreator formCreators[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; ++i) 
	{
		if (formName == formNames[i]) 
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Intern cannot create " << formName << " form." << std::endl;
	return 0;
}

AForm *Intern::createShrubberyCreationForm(std::string target) 
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string target) 
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string target) 
{
	return new PresidentialPardonForm(target);
}