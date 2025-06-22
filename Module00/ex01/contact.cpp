/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:37:19 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/06/21 14:02:03 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(){} 

Contact::Contact(
	const std::string first_name,
	const std::string last_name,
	const std::string nick_name,
	const std::string phone_number,
	const std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nick_name = nick_name;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string Contact::get_first_name()
{
	return this->first_name;
}

std::string Contact::get_last_name()
{
	return this->last_name;
}

std::string Contact::get_nick_name()
{
	return this->nick_name;
}

std::string Contact::get_phone_number()
{
	return this->phone_number;
}

std::string Contact::get_darkest_secret()
{
	return this->darkest_secret;
}