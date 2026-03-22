/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:33:05 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/22 15:54:35 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
#include <cstdlib>

bool bsp( Point const a, Point const b, Point const c, Point const point);
 
int main(int argc, char **argv)
{
	if (argc != 9)
	{
		std::cerr << "Usage: " << argv[0] << " <a_x> <a_y> <b_x> <b_y> <c_x> <c_y> <p_x> <p_y>" << std::endl;
		return 1;
	}

	Point a(std::atoi(argv[1]), std::atoi(argv[2]));
	Point b(std::atoi(argv[3]), std::atoi(argv[4]));
	Point c(std::atoi(argv[5]), std::atoi(argv[6]));

	Point point(std::atoi(argv[7]), std::atoi(argv[8]));
	
	if (bsp(a, b, c, point))
		std::cout << "ok" << std::endl;
	else
		std::cout << "ko" << std::endl;

	return 0;
}
