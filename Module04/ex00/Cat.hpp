/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:06 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/30 02:05:21 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT
#define CAT

#include "Animal.hpp"

class Cat : public Animal
{
	public:
			Cat();
			Cat(const Cat &other);
	Cat		&operator=(const Cat &other);
			~Cat();
	void	makeSound() const;
};

#endif