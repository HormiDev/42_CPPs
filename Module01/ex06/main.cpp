/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 03:51:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/18 04:57:56 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl	harl;
	std::string levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "I am not sure how tired I am today..."};
	int level = 0;

	if (argc != 2)
	{
		std::cerr << "Error: Usage: " << argv[0] << " <complaint>" << std::endl;
		return (1);
	}
	while (level < 5)
	{
		if (levels[level] == argv[1])
			break;
		level++;
	}
	switch (level)
	{
	case 0:
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case 1:
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case 2:
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
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