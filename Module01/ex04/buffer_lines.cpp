/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_lines.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:17:30 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/07/16 22:43:08 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_lines.hpp"
#include <iostream>

size_t ft_count_char_in_string(char c, const std::string str)
{
	size_t count = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == c)
			count++;
	}
	return count;
}

buffer_lines::buffer_lines() {}

buffer_lines::buffer_lines(std::ifstream *infile, std::string to_replace, std::string replacement)
{
	this->infile = infile;
	this->to_replace = to_replace;
	this->replacement = replacement;
	if (!(*infile).is_open())
		throw std::runtime_error("Error: Could not open file."); // capturar excepcion en el main
	if (to_replace.empty() || replacement.empty()) // revisar
		throw std::invalid_argument("Error: Replacement strings cannot be empty.");
	if (to_replace.empty())
		throw std::invalid_argument("Error: String to replace cannot be empty.");
	buffer.clear();
	n_lines = ft_count_char_in_string('\n', to_replace) + 1;
	int i = 0;
	while (i < n_lines)
	{
		std::string line;
		if (!std::getline((*infile), line))
			break;
		buffer += line;
		i++;
		if (i < n_lines)
			buffer += '\n';
	}
	std::cout << buffer << std::endl;
}