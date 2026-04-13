/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 02:26:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/13 03:26:43 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character:public ICharacter
{
	public:
    						Character();
							Character(const Character& other);
		Character			&operator=(const Character& other);
							~Character();

							Character(std::string const &name);
		std::string const	&getName() const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);
		friend std::ostream	&operator<<(std::ostream &out, const Character &character);
	private:
		std::string	name;
		AMateria*	inventory[4];
};

#endif