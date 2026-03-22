/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 02:37:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/22 03:50:11 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed point_side_of_line(Point const point, Point const line_start, Point const line_end)
{
	return ((line_end.getX() - line_start.getX()) * (point.getY() - line_start.getY())
			- (line_end.getY() - line_start.getY()) * (point.getX() - line_start.getX()));
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed side1 = point_side_of_line(p, a, b);
	Fixed side2 = point_side_of_line(p, b, c);
	Fixed side3 = point_side_of_line(p, c, a);

	return (side1 > 0 && side2 > 0 && side3 > 0) || (side1 < 0 && side2 < 0 && side3 < 0);
}