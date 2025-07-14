/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_lines.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:17:30 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/07/14 16:04:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_lines.hpp"

int buffer_lines::count_lines()
{
	int i = 0;
	int count = 0;
	
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

buffer_lines::buffer_lines(std::ifstream infile, std::string to_replace, std::string replacement)

{
	this->infile = std::move(infile);
	this->to_replace = to_replace;
	this->replacement = replacement;
	if (!infile.is_open())
		throw std::runtime_error("Error: Could not open file."); // capturar excepcion en el main
	if (to_replace.empty() || replacement.empty()) // revisar
		throw std::invalid_argument("Error: Replacement strings cannot be empty.");
	if (to_replace.empty())
		throw std::invalid_argument("Error: String to replace cannot be empty.");
	buffer.clear();
	n_lines = 1;
	
}