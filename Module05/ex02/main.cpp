/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:21:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/16 23:42:58 by ide-dieg         ###   ########.fr       */
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
	try
	{
		Bureaucrat bureaucrat("John Doe", 1);
		std::cout << bureaucrat << std::endl;

		AForm *form1 = new ShrubberyCreationForm("home");
		AForm *form2 = new RobotomyRequestForm("robot");
		AForm *form3 = new PresidentialPardonForm("president");

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;

		bureaucrat.signAForm(*form1);
		bureaucrat.signAForm(*form2);
		bureaucrat.signAForm(*form3);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}
	
}