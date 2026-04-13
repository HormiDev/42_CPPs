/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 13:37:17 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/12 17:56:56 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
					Ice();
					Ice(const Ice &other);
		Ice			&operator=(const Ice &other);
					~Ice();

		Ice			*clone() const;
		void		use(ICharacter &target);
};

#endif