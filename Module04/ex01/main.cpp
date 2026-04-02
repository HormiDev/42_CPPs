/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 03:59:34 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/02 04:41:56 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

	Dog a;
	a.setIdea("Bone");
	a.setIdea("Play");
	Dog b(a);
	b.setIdea("Fetch");
	Dog c = b;
	c.setIdea("Roll over");

	a.setIdea("Sit");
	b.setIdea("Stay");
	c.setIdea("Come");

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	Cat e;
	e.setIdea("Mouse");
	Cat f(e);
	f.setIdea("Purr");
	Cat g = f;
	g.setIdea("Hunt");

	e.setIdea("Sleep");
	f.setIdea("Eat");
	g.setIdea("Play");

	std::cout << e << std::endl;
	std::cout << f << std::endl;
	std::cout << g << std::endl;

    return 0;
}