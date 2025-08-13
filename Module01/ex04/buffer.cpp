/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:13:19 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/07/19 17:36:08 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.hpp"

buffer::buffer(std::ifstream *infile, std::string to_replace, std::string replacement)
{
	this->infile = infile;
	this->to_replace = to_replace;
	this->replacement = replacement;
	this->buffer_length = to_replace.size() * 2;
}

buffer::~buffer()
{
	delete[] str_buffer; // Free the allocated memory
}

buffer::buffer() {}

std::string buffer::read()
{
	if (!(*infile).is_open())
		throw std::runtime_error("Error: Could not open file."); // capturar excepcion en el main
	if (to_replace.empty() || replacement.empty()) // revisar
		throw std::invalid_argument("Error: Replacement strings cannot be empty.");
	if (to_replace.empty())
		throw std::invalid_argument("Error: String to replace cannot be empty.");
	
	(*(this->infile)).read(reinterpret_cast<char *>(str_buffer), buffer_length);
}

