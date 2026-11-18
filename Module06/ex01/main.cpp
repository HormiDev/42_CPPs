/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:19:32 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/11/18 15:16:53 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data a;
	a.data_str = "hola";
	Data b;
	b.data_str = "adios";

	Data *ptr = NULL;

	uintptr_t a_uint = Serializer::serialize(&a);
	uintptr_t b_uint = Serializer::serialize(&b);
	
	std::cout << "a_ptr = " << &a << std::endl;
	std::cout << "a_uintptr_t = " << a_uint << std::endl;
	std::cout << "b_ptr = " << &b << std::endl;
	std::cout << "b_uintptr_t = " << b_uint << std::endl;

	ptr = 
	return 0;
}