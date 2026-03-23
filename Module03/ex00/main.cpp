/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 00:16:55 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/23 02:49:45 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a;
	ClapTrap b("Marvin");
	ClapTrap c(a);

	c.takeDamage(200);
	c.attack("all");
	c = ClapTrap("ide-dieg");
	a = ClapTrap("HormiDev");

	for(int i = 0; i < 10; i++)
	{
		a.attack("Marvin");
		a.takeDamage(7);
		a.beRepaired(3);
	}
}