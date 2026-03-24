/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:16:55 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/24 02:17:32 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap a;
	FragTrap b("Marvin");
	FragTrap c(a);

	c.takeDamage(200);
	c.attack("all");
	c = FragTrap("ide-dieg");
	a = FragTrap("HormiDev");

	for(int i = 0; i < 10; i++)
	{
		a.attack("Marvin");
		a.takeDamage(7);
		a.beRepaired(3);
		c.highFivesGuys();
	}
}