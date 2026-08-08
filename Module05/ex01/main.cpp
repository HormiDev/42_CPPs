/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:21:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/08 17:49:00 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		Form form1("Form1", 0, 100);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		Form form2("Form2", 151, 100);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		Form form3("Form3", 50, 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		Form form4("Form4", 50, 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	Form form5("Form5", 50, 100);
	std::cout << form5 << std::endl;
	marvin.signForm(form5);
	std::cout << form5 << std::endl;
	marvin.signForm(form5);
}