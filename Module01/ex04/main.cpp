/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 13:18:39 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/07/16 22:19:44 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include "buffer_lines.hpp"

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
	buffer_lines buffer(&infile, searchString, replaceString);
	
	infile.close();
	outfile.close();
	return 0;
}