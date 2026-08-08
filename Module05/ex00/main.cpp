/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 15:21:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/07 19:02:31 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define RED "\033[1;31m"
#define NC "\033[0m"

int main()
{
	Bureaucrat marvin("Marvin", 42);
	std::cout << marvin << std::endl;
	std::cout << marvin.getName() << std::endl;
	std::cout << marvin.getGrade() << std::endl;
	try
	{
		Bureaucrat bureaucrat1;
		std::cout << bureaucrat1 << std::endl;

		Bureaucrat bureaucrat2("Jeltz", 1);
		std::cout << bureaucrat2 << std::endl;

		Bureaucrat bureaucrat3("Zaphod", 150);
		std::cout << bureaucrat3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Ford", 0);
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Ford", 151);
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Arthur", 2);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat("Trillian", 149);
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << RED << e.what() << NC << std::endl;
	}
}