/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:34:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/01/29 02:46:38 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
	this->contact_index = 0;
}

int check_first_name(std::string str)
{
	size_t i;

	i = 0;
	while (i < str.length())
	{
		if (!isalpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int check_last_name(std::string str)
{
	size_t i;

	i = 0;
	while (i < str.length())
	{
		if (!isalpha(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int check_nickname(std::string str)
{
	size_t i;

	i = 0;
	while (i < str.length())
	{
		if (!isgraph(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int check_phone_number(std::string str)
{
    size_t i;

    i = 0;
    if (str[0] == '+')
        i++;
    if (i == 1 && str.length() == 1)
        return (0);
    while (i < str.length())
    {
        if (!isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void PhoneBook::addContact(void)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;
	size_t i;
	std::string whitespace_chars = " \t\n\v\f\r";

	i = 0;
	while (i < 3)
	{
		std::cout << BOLD << YELLOW << "Enter first name: " << RESET;
		std::getline(std::cin, first_name);
		if (std::cin.eof())
			return;
		first_name.erase(0, first_name.find_first_not_of(whitespace_chars));
		first_name.erase(first_name.find_last_not_of(whitespace_chars) + 1);
		if (check_first_name(first_name) && !first_name.empty())
			break ;
		if (first_name.empty())
			std::cout << RED << BOLD << "Error: First name cannot be empty." << RESET << std::endl;
		else
			std::cout << RED << BOLD << "Error: First name must contain only alphabetic characters." << RESET << std::endl;
		if (i == 2)
			return ;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		std::cout << BOLD << YELLOW << "Enter last name: " << RESET;
		std::getline(std::cin, last_name);
		if (std::cin.eof())
			return;
		last_name.erase(0, last_name.find_first_not_of(whitespace_chars));
		last_name.erase(last_name.find_last_not_of(whitespace_chars) + 1);
		if (check_last_name(last_name) && !last_name.empty())
			break ;
		if (last_name.empty())
			std::cout << RED << BOLD << "Error: Last name cannot be empty." << RESET << std::endl;
		else
			std::cout << RED << BOLD << "Error: Last name must contain only alphabetic characters." << RESET << std::endl;
		if (i == 2)
			return ;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		std::cout << BOLD << YELLOW << "Enter nick name: " << RESET;
		std::getline(std::cin, nick_name);
		if (std::cin.eof())
			return;
		nick_name.erase(0, nick_name.find_first_not_of(whitespace_chars));
		nick_name.erase(nick_name.find_last_not_of(whitespace_chars) + 1);
		if (check_nickname(nick_name) && !nick_name.empty())
			break ;
		if (nick_name.empty())
			std::cout << RED << BOLD << "Error: Nick name cannot be empty." << RESET << std::endl;
		else
			std::cout << RED << BOLD << "Error: Nick name must contain only printable characters." << RESET << std::endl;
		if (i == 2)
			return ;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		std::cout << BOLD << YELLOW << "Enter phone number: " << RESET;
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
			return;
		phone_number.erase(0, phone_number.find_first_not_of(whitespace_chars));
		phone_number.erase(phone_number.find_last_not_of(whitespace_chars) + 1);
		if (check_phone_number(phone_number) && !phone_number.empty())
			break ;
		if (phone_number.empty())
			std::cout << RED << BOLD << "Error: Phone number cannot be empty." << RESET << std::endl;
		else
			std::cout << RED << BOLD << "Error: Phone number must contain only digits and an optional leading '+'." << RESET << std::endl;
		if (i == 2)
			return ;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		std::cout << BOLD << YELLOW << "Enter darkest secret: " << RESET;
		std::getline(std::cin, darkest_secret);
		if (std::cin.eof())
			return;
		i++;
		if (!darkest_secret.empty())
			break ;
		if (i == 3)
			return ;
		std::cout << RED << BOLD << "Error: Darkest secret cannot be empty." << RESET << std::endl;
		i++;
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
	if (std::cin.eof())
		return;
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

