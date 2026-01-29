/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:59:15 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/01/29 01:16:01 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "colors.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << CYAN << BOLD << "phonebook> " << RESET;
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
		if (std::cin.eof())
		{
			std::cout << std::endl << RED << BOLD << "EOF detected. Exiting phonebook." << RESET << std::endl;
			break;
		}
	}
	return 0;
}