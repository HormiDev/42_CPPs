/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:34:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/06/22 02:35:41 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
	this->contact_index = 0;
}

void PhoneBook::addContact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << BOLD << YELLOW << "Enter first name: " << RESET;
	std::getline(std::cin, first_name);
	std::cout << BOLD << YELLOW << "Enter last name: " << RESET;
	std::getline(std::cin, last_name);
	std::cout << BOLD << YELLOW << "Enter nick name: " << RESET;
	std::getline(std::cin, nick_name);
	std::cout << BOLD << YELLOW << "Enter phone number: " << RESET;
	std::getline(std::cin, phone_number);
	std::cout << BOLD << YELLOW << "Enter darkest secret: " << RESET;
	std::getline(std::cin, darkest_secret);
	if (first_name.empty() || last_name.empty() || nick_name.empty() ||
		phone_number.empty() || darkest_secret.empty())
	{
		std::cout << RED << BOLD << "Error: All fields must be filled." << RESET << std::endl;
		return;
	}
	this->contacts[this->contact_index] = Contact(
		first_name, last_name, nick_name, phone_number, darkest_secret);
	this->contact_index++;
	if (this->contact_index >= 8)
		this->contact_index = 0;
	if (this->contact_count < 8)
		this->contact_count++;
}

void PhoneBook::print_table_contact(void)
{
	int i;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	i = 0;
	while (i < this->contact_count)
	{
		std::cout << "|         " << i << "|";
		if (this->contacts[i].get_first_name().length() > 10)
			std::cout << this->contacts[i].get_first_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->contacts[i].get_first_name() << "|";
		if (this->contacts[i].get_last_name().length() > 10)
			std::cout << this->contacts[i].get_last_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->contacts[i].get_last_name() << "|";
		if (this->contacts[i].get_nick_name().length() > 10)
			std::cout << this->contacts[i].get_nick_name().substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << this->contacts[i].get_nick_name() << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

void PhoneBook::searchContact(void)
{
	//int			index;
	std::string index_str;

	this->print_table_contact();
	std::cout << BOLD << YELLOW << "Enter index: " << RESET;
	std::getline(std::cin, index_str);
	if (index_str.empty())
	{
		std::cout << RED << BOLD << "Error: Index cannot be empty." << RESET << std::endl;
		return;
	}
	if (index_str.length() > 1 || !isdigit(index_str[0]))
	{
		std::cout << RED << BOLD << "Error: Index must be a single digit." << RESET << std::endl;
		return;
	}
	int index = index_str[0] - '0';
	if (index < 0 || index >= this->contact_count)
	{
		std::cout << RED << BOLD << "Error: Invalid index." << RESET << std::endl;
		return;
	}
	std::cout << BOLD << CYAN << "First Name: " << RESET
			  << this->contacts[index].get_first_name() << std::endl;
	std::cout << BOLD << CYAN << "Last Name: " << RESET
			  << this->contacts[index].get_last_name() << std::endl;
	std::cout << BOLD << CYAN << "Nick Name: " << RESET
			  << this->contacts[index].get_nick_name() << std::endl;
	std::cout << BOLD << CYAN << "Phone Number: " << RESET
			  << this->contacts[index].get_phone_number() << std::endl;
	std::cout << BOLD << CYAN << "Darkest Secret: " << RESET
			  << this->contacts[index].get_darkest_secret() << std::endl;
}

