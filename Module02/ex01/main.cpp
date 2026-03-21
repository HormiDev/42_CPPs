/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:33:05 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/20 20:45:30 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <climits>

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed e(1000000.7f);
	Fixed f(INT_MAX);
	Fixed g(INT_MIN);
	Fixed h(3.994f);
	Fixed max(8388607);
	Fixed min(-8388608);
	Fixed FixedMax;
	Fixed FixedMin;
	Fixed FractionalMax;
	Fixed FractionalMin;

	a = Fixed( 1234.4321f );
	FixedMax.setRawBits(INT_MAX);
	FixedMin.setRawBits(INT_MIN);
	FractionalMax.setRawBits(255);
	FractionalMin.setRawBits(-255);
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "max is " << max << std::endl;
	std::cout << "min is " << min << std::endl;
	std::cout << "FixedMax is " << FixedMax << std::endl;
	std::cout << "FixedMin is " << FixedMin << std::endl;
	std::cout << "FractionalMax is " << FractionalMax << std::endl;
	std::cout << "FractionalMin is " << FractionalMin << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "f is " << f.toInt() << " as integer" << std::endl;
	std::cout << "g is " << g.toInt() << " as integer" << std::endl;
	std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	std::cout << "max is " << max.toInt() << " as integer" << std::endl;
	std::cout << "min is " << min.toInt() << " as integer" << std::endl;
	std::cout << "FixedMax is " << FixedMax.toInt() << " as integer" << std::endl;
	std::cout << "FixedMin is " << FixedMin.toInt() << " as integer" << std::endl;
	std::cout << "FractionalMax is " << FractionalMax.toInt() << " as integer" << std::endl;
	std::cout << "FractionalMin is " << FractionalMin.toInt() << " as integer" << std::endl;

	return 0;
}