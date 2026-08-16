/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 01:23:27 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/16 23:32:20 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default_target") 
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) 
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) 
{
	if (this != &other) 
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
	if (!getIsSigned())
		throw std::runtime_error("ShrubberyCreationForm is not signed");
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::ofstream outfile(target + "_shrubbery");
	if (!outfile)
	{
		std::cerr << "Error: Could not create file " << target + "_shrubbery" << std::endl;
		return;
	}

	outfile << "       _-_\n"
	        << "    /~~   ~~\\\n"
	        << " /~~         ~~\\\n"
	        << "{               }\n"
	        << " \\  _-     -_  /\n"
	        << "   ~  \\\\ //  ~\n"
	        << "_- -   | | _- _\n"
	        << "  _ -  | |   -_\n"
	        << "      // \\\\\n";

	outfile.close();
}