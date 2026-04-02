/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:06 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/02 04:28:03 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG
#define DOG

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
						Dog();
						Dog(const Dog &other);
		Dog				&operator=(const Dog &other);
						~Dog();
		void			makeSound() const;
		void			setIdea(const std::string &idea);
		friend std::ostream	&operator<<(std::ostream &os, const Dog &dog);

	private:
		Brain	*brain;
};

#endif