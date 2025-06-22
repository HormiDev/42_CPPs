/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 01:42:49 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/06/21 22:55:01 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "colors.hpp"
#include "contact.hpp"

class PhoneBook
{
	private:
		int			contact_count;
		int			contact_index;
		Contact		contacts[8];
		void print_table_contact(void);
	public:
		PhoneBook();
		void addContact(void);
		void searchContact(void);
};


#endif