/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:18:39 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/01/18 21:21:53 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "\033[31m" << "Error: Invalid arguments." << std::endl;
		std::cerr << "\033[33m"<< "Use: " << argv[0] << " <File_name> <Search_string> <Replace_string>" << "\033[0m" << std::endl;
		return 1;
	}
	std::string fileName = argv[1];
	std::string searchString = argv[2];
	std::string replaceString = argv[3];
	if (fileName.empty() || searchString.empty() || replaceString.empty())
	{
		std::cerr << "\033[31m" << "Error: Arguments cannot be empty." << "\033[0m" << std::endl;
		return 1;
	}
	std::ifstream infile(&fileName[0]);
	if (!infile.is_open())
	{
		std::cerr << "\033[31m" << "Error: Could not open file '" << fileName << "'." << "\033[0m" << std::endl;
		return 1;
	}
	std::string outfileName = fileName + ".replace";
	std::ofstream outfile(&outfileName[0]);
	if (!outfile.is_open())
	{
		std::cerr << "\033[31m" << "Error: Could not create file '" << outfileName << "'." << "\033[0m" << std::endl;
		infile.close();
		return 1;
	}

	std::cout << "\033[32m" << "File '" << fileName << "' opened successfully." << "\033[0m" << std::endl;

	size_t search_len = searchString.size();
	size_t buffer_size = search_len * 2;
	std::string buffer;
	buffer.resize(buffer_size);
	std::streamsize bytesRead;
	size_t pos;

	infile.read(&buffer[0], buffer_size);
	while (infile.gcount() > 0)
	{
		bytesRead = infile.gcount();
		pos = buffer.find(searchString, 0);
		if (pos == std::string::npos)
		{
			outfile << buffer.substr(0, search_len);
			buffer = buffer.substr(search_len, search_len);
			buffer.resize(buffer_size);
			infile.read(&buffer[search_len], search_len);
		}
		else
		{
			outfile << buffer.substr(0, pos) << replaceString;
			buffer = buffer.substr(pos + search_len, buffer_size - (pos + search_len));
			buffer.resize(buffer_size);
			infile.read(&buffer[buffer_size - (pos + search_len)], pos + search_len);
		}
	}
	outfile << buffer.substr(0, bytesRead);
	
	infile.close();
	outfile.close();
	return 0;
}