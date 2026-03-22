/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:33:05 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/22 03:50:51 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <climits>

bool bsp( Point const a, Point const b, Point const c, Point const point);
 
int main( void ) {
	Point a(1, 1);
	Point b(1, 3);
	Point c(3, 1);

	Point point(1, 1);
	
	if (bsp(a, b, c, point))
		std::cout << "The point" << point << " is inside the triangle: " << a << ", " << b << ", " << c << std::endl;
	else
		std::cout << "The point" << point << " is not inside the triangle: " << a << ", " << b << ", " << c << std::endl;

	return 0;
}
