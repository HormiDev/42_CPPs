/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:36:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/18 04:43:20 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}
}

void Harl::debug(void)
{
	std::cout << CYAN << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}

void Harl::info(void)
{
	std::cout << GREEN << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << RESET << std::endl;
}

void Harl::warning(void)
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << RESET << std::endl;
}

void Harl::error(void)
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
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