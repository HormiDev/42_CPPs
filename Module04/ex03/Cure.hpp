/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 17:14:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/12 19:05:09 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
					Cure();
					Cure(const Cure &other);
		Cure		&operator=(const Cure &other);
					~Cure();

		Cure		*clone() const;
		void		use(ICharacter &target);
};

#endif