/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:36:10 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/11/18 19:04:22 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

Base::~Base() {}

Base* generate(void)
{
	timeval ahora;
    gettimeofday(&ahora, NULL);

	int random = ahora.tv_usec % 3;
	if (random == 0)
	{
		std::cout << "Generated type: A" << std::endl;
		return new A();
	}
	else if (random == 1)
	{
		std::cout << "Generated type: B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generated type: C" << std::endl;
		return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a; // Avoid unused variable warning
	}
	catch (...)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b; // Avoid unused variable warning
		}
		catch (...)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
				(void)c; // Avoid unused variable warning
			}
			catch (...)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}