/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:51:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/25 13:55:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl	harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int level = 0;

	if (argc != 2)
	{
		std::cerr << "Error: Usage: " << argv[0] << " <complaint>" << std::endl;
		return (1);
	}
	while (level < 4)
	{
		if (levels[level] == argv[1])
			break;
		level++;
	}
	switch (level)
	{
	case 0:
		harl.complain("DEBUG");
		// fallthrough
	case 1:
		harl.complain("INFO");
		// fallthrough
	case 2:
		harl.complain("WARNING");
		// fallthrough
	case 3:
		harl.complain("ERROR");
		break;
	case 4:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	default:
		break;
	}
    return (0);
}