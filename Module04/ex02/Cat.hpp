/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 04:33:06 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/02 04:26:05 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT
#define CAT

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
				Cat();
				Cat(const Cat &other);
		Cat		&operator=(const Cat &other);
				~Cat();
		void	makeSound() const;
		void	setIdea(const std::string &idea);
		friend std::ostream	&operator<<(std::ostream &os, const Cat &cat);

	private:
		Brain	*brain;
};

#endif