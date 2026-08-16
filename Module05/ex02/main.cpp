/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:21:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/08 20:06:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#define RED "\033[1;31m"
#define NC "\033[0m"

int main()
{
	Bureaucrat marvin("Marvin", 42);
	Bureaucrat jeltz("Jeltz", 1);
	Bureaucrat zaphod("Zaphod", 150);

	std::cout << marvin << std::endl;
	std::cout << jeltz << std::endl;
	std::cout << zaphod << std::endl;

	try
	{
		AForm AForm1("AForm1", 0, 100);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		AForm AForm2("AForm2", 151, 100);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		AForm AForm3("AForm3", 50, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		AForm AForm4("AForm4", 50, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	AForm AForm5("AForm5", 50, 100);
	std::cout << AForm5 << std::endl;
	marvin.signAForm(AForm5);
	std::cout << AForm5 << std::endl;
	marvin.signAForm(AForm5);
}