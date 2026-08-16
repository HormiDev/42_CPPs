/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 01:24:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/16 23:36:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default_target") 
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) 
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{
	if (this != &other) 
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
	if (!getIsSigned())
		throw std::runtime_error("RobotomyRequestForm is not signed");
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "Trrrrrrrrr..." << std::endl;

	if (rand() % 2)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "." << std::endl;
}