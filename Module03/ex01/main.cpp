/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:16:55 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/24 01:54:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a;
	ScavTrap b("Marvin");
	ScavTrap c(a);

	c.takeDamage(200);
	c.attack("all");
	c = ScavTrap("ide-dieg");
	a = ScavTrap("HormiDev");

	for(int i = 0; i < 10; i++)
	{
		a.attack("Marvin");
		a.takeDamage(7);
		a.beRepaired(3);
		c.guardGate();
	}
}