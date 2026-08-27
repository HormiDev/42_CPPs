/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:21:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/28 00:56:26 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RED "\033[1;31m"
#define NC "\033[0m"

int main()
{
	Intern someRandomIntern;
	AForm *shrubbery = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm *robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Marvin");

	if (!shrubbery || !robotomy || !pardon)
	{
		std::cerr << RED << "Failed to create forms." << NC << std::endl;
		return 1;
	}

	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 50);
	Bureaucrat intern("Intern", 150);

	try
	{
		shrubbery->execute(boss);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		shrubbery->beSigned(employee);
		shrubbery->execute(employee);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		robotomy->beSigned(intern);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		robotomy->beSigned(employee);
		robotomy->execute(boss);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		pardon->beSigned(employee);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		pardon->beSigned(boss);
		pardon->execute(boss);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	delete shrubbery;
	delete robotomy;
	delete pardon;

	return 0;
}
