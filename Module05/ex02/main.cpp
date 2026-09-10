/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:21:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/28 00:05:26 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[1;31m"
#define NC "\033[0m"

int main()
{
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("Marvin");
	PresidentialPardonForm pardon("Zapod");

	Bureaucrat boss("Boss", 1);
	Bureaucrat employee("Employee", 50);
	Bureaucrat intern("Intern", 150);

	try
	{
		shrubbery.execute(boss);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		shrubbery.beSigned(employee);
		shrubbery.execute(employee);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		robotomy.beSigned(intern);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		robotomy.beSigned(employee);
		robotomy.execute(boss);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		pardon.beSigned(employee);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		pardon.beSigned(boss);
		pardon.execute(boss);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	std::cout << "\n--- Bureaucrat tests ---\n" << std::endl;

	ShrubberyCreationForm shrubbery2("garden");
	RobotomyRequestForm robotomy2("Marvin");
	PresidentialPardonForm pardon2("Zapod");

	boss.executeForm(shrubbery2);
	employee.signAForm(shrubbery2);
	employee.executeForm(shrubbery2);
	intern.signAForm(robotomy2);
	employee.signAForm(robotomy2);
	boss.executeForm(robotomy2);
	employee.signAForm(pardon2);
	boss.signAForm(pardon2);
	boss.executeForm(pardon2);

	return 0;
}
