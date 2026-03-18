/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:36:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/18 04:43:00 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

void Harl::debug(void)
{
	std::cout << CYAN << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << GREEN << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << YELLOW << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n" << RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << RED << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << RESET << std::endl;
}

void Harl::complain(std::string level)
{
	if (level == "DEBUG")
		debug();
	else if (level == "INFO")
		info();
	else if (level == "WARNING")
		warning();
	else if (level == "ERROR")
		error();
}