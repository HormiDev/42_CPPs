/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:06 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/30 02:05:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG
#define DOG

#include "Animal.hpp"

class Dog : public Animal
{
	public:
			Dog();
			Dog(const Dog &other);
	Dog		&operator=(const Dog &other);
			~Dog();
	void	makeSound() const;
};

#endif