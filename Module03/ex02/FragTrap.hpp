/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 00:25:41 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/24 02:14:52 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
					FragTrap();
					FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);
					~FragTrap();
					FragTrap(std::string name);
		void		attack(const std::string& target);
		void 		highFivesGuys(void);
};

#endif