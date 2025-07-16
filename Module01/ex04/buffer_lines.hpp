/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_lines.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:49:19 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/07/16 22:37:37 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_LINES
#define BUFFER_LINES

#include <string>
#include <fstream>

class buffer_lines
{
	private:
		std::string		buffer;
		std::string		to_replace;
		std::string		replacement;
		std::ifstream	*infile;
		int				n_lines;
		buffer_lines();
		int count_lines();
		int read_lines();
		
	public:
		buffer_lines(std::ifstream *infile, std::string to_replace, std::string replacement);
		std::string get_line();
		int replace(std::string to_replace, std::string replacement);
};

size_t ft_count_char_in_string(char c, const std::string str);

#endif