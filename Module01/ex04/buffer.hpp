/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:13:08 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/07/18 20:33:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include <fstream>
#include <string>

class buffer
{
	private:
		std::string *str_buffer;
		std::ifstream *infile;
		std::string to_replace;
		std::string replacement;
		size_t buffer_length;
		buffer();

	public:
		buffer(std::ifstream *infile, std::string to_replace, std::string replacement);
		~buffer();
		std::string read();
};

#endif
