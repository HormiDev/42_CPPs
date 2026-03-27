/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:16:55 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/27 00:43:27 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap a;
	a.whoAmI();
	std::cout << a << std::endl;
	DiamondTrap b("Marvin");
	b.whoAmI();
	std::cout << b << std::endl;
	DiamondTrap c(a);
	c.whoAmI();
	std::cout << b << std::endl;

	c.takeDamage(200);
	c.attack("all");
	c = DiamondTrap("ide-dieg");
	c.whoAmI();
	a = DiamondTrap("HormiDev");
	a.whoAmI();

	for(int i = 0; i < 10; i++)
	{
		a.attack("Marvin");
		a.takeDamage(7);
		a.beRepaired(3);
		c.highFivesGuys();
	}
}