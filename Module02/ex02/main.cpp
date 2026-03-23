/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:33:05 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/22 22:04:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>
 
int main( void ) {
	Fixed a(100);
	Fixed b(100.1f);
	Fixed c(100.2f);

	std::cout << CYAN << "\nTEST OPERATOR > :" << RESET << std::endl;
	if (a > b)
		std::cout << a << " is > than " << b << std::endl;
	else
		std::cout << a << " is not > than " << b << std::endl;
	if (a > c)
		std::cout << a << " is > than " << c << std::endl;
	else
		std::cout << a << " is not > than " << c << std::endl;
	if (b > c)
		std::cout << b << " is > than " << c << std::endl;
	else
		std::cout << b << " is not > than " << c << std::endl;
	if (c > c)
		std::cout << c << " is > than " << c << std::endl;
	else
		std::cout << c << " is not > than " << c << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR < :" << RESET << std::endl;
	if (a < b)
		std::cout << a << " is < than " << b << std::endl;
	else
		std::cout << a << " is not < than " << b << std::endl;
	if (a < c)
		std::cout << a << " is < than " << c << std::endl;
	else
		std::cout << a << " is not < than " << c << std::endl;
	if (b < c)
		std::cout << b << " is < than " << c << std::endl;
	else
		std::cout << b << " is not < than " << c << std::endl;
	if (c < c)
		std::cout << c << " is < than " << c << std::endl;
	else
		std::cout << c << " is not < than " << c << std::endl;
	
	std::cout << CYAN << "\nTEST OPERATOR >= :" << RESET << std::endl;
	if (a >= b)
		std::cout << a << " is >= than " << b << std::endl;
	else
		std::cout << a << " is not >= than " << b << std::endl;
	if (a >= c)
		std::cout << a << " is >= than " << c << std::endl;
	else
		std::cout << a << " is not >= than " << c << std::endl;
	if (b >= c)
		std::cout << b << " is >= than " << c << std::endl;
	else
		std::cout << b << " is not >= than " << c << std::endl;
	if (c >= c)
		std::cout << c << " is >= than " << c << std::endl;
	else
		std::cout << c << " is not >= than " << c << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR <= :" << RESET << std::endl;
	if (a <= b)
		std::cout << a << " is <= than " << b << std::endl;
	else
		std::cout << a << " is not <= than " << b << std::endl;
	if (a <= c)
		std::cout << a << " is <= than " << c << std::endl;
	else
		std::cout << a << " is not <= than " << c << std::endl;
	if (b <= c)
		std::cout << b << " is <= than " << c << std::endl;
	else
		std::cout << b << " is not <= than " << c << std::endl;
	if (c <= c)
		std::cout << c << " is <= than " << c << std::endl;
	else
		std::cout << c << " is not <= than " << c << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR == :" << RESET << std::endl;
	if (a == b)
		std::cout << a << " is == than " << b << std::endl;
	else
		std::cout << a << " is not == than " << b << std::endl;
	if (a == c)
		std::cout << a << " is == than " << c << std::endl;
	else
		std::cout << a << " is not == than " << c << std::endl;
	if (b == c)
		std::cout << b << " is == than " << c << std::endl;
	else
		std::cout << b << " is not == than " << c << std::endl;
	if (c == c)
		std::cout << c << " is == than " << c << std::endl;
	else
		std::cout << c << " is not == than " << c << std::endl;
	
	std::cout << CYAN << "\nTEST OPERATOR != :" << RESET << std::endl;
	if (a != b)
		std::cout << a << " is != than " << b << std::endl;
	else
		std::cout << a << " is not != than " << b << std::endl;
	if (a != c)
		std::cout << a << " is != than " << c << std::endl;
	else
		std::cout << a << " is not != than " << c << std::endl;
	if (b != c)
		std::cout << b << " is != than " << c << std::endl;
	else
		std::cout << b << " is not != than " << c << std::endl;
	if (c != c)
		std::cout << c << " is != than " << c << std::endl;
	else
		std::cout << c << " is not != than " << c << std::endl;
	
	a = 10;
	b = 2;
	c = 0.5f;

	std::cout << CYAN << "\nTEST OPERATOR + :" << RESET << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " + " << c << " = " << a + c << std::endl;
	std::cout << b << " + " << c << " = " << b + c << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR - :" << RESET << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " - " << c << " = " << a - c << std::endl;
	std::cout << b << " - " << c << " = " << b - c << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR * :" << RESET << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " * " << c << " = " << a * c << std::endl;
	std::cout << b << " * " << c << " = " << b * c << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR / :" << RESET << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
	std::cout << a << " / " << c << " = " << a / c << std::endl;
	std::cout << b << " / " << c << " = " << b / c << std::endl;

	Fixed e(6);
	Fixed f(-2);
	Fixed g;
	std::cout << e << " / " << g << " = " << e / g << std::endl;
	std::cout << f << " / " << g << " = " << f / g << std::endl;

	e = 10.0f / 0.0f;
	f = -10.0f / 0.0f;
	g = 0.0f / 0.0f;

	std::cout << "+inf " << e << std::endl;
	std::cout << "-inf " << f << std::endl;
	std::cout << "NaN " << g << std::endl;

	int h = e.getRawBits();

	std::cout << "Raw bits of +inf: " << h << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR ++ :" << RESET << std::endl;
	std::cout << "++" << a << " = " << ++a << std::endl;
	std::cout << a << "++ = " << a++ << " and a value is " << a << std::endl;

	std::cout << CYAN << "\nTEST OPERATOR -- :" << RESET << std::endl;
	std::cout << "--" << a << " = " << --a << std::endl;
	std::cout << a << "-- = " << a-- << " and a value is " << a << std::endl;

	std::cout << CYAN << "\nTEST STATIC METHODS min :" << RESET << std::endl;
	std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << std::endl;
	std::cout << "min(" << a << ", " << c << ") = " << Fixed::min(a, c) << std::endl;
	std::cout << "min(" << b << ", " << c << ") = " << Fixed::min(b, c) << std::endl;

	std::cout << CYAN << "\nTEST STATIC METHODS max :" << RESET << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl;
	std::cout << "max(" << a << ", " << c << ") = " << Fixed::max(a, c) << std::endl;
	std::cout << "max(" << b << ", " << c << ") = " << Fixed::max(b, c) << std::endl;

	return 0;
}
