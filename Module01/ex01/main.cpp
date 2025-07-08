/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:27:28 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/07/07 13:57:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>


int main(int argc, char **argv)
{
	int n_zombies;
	int i;

	if (argc != 3)
	{
		std::cerr << "\033[31m" << "Error: Invalid arguments." << std::endl;
		std::cerr << "\033[33m"<< "Use: " << argv[0] << " <Number of zombies> <Name>" << "\033[0m" << std::endl;
		return 1;
	}
	n_zombies = atoi(argv[1]);
	if (n_zombies < 0)
	{
		std::cerr << "\033[31m" << "Error: Number of zombies must be a positive integer." << std::endl;
		return 1;
	}
	Zombie *horde = zombieHorde(n_zombies, argv[2]);
	i = 0;
	while(i < n_zombies)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}