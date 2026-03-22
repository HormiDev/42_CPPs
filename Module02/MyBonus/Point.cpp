/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:19:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/22 02:32:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

Point::Point(const Point &other) : x(other.getX()), y(other.getY()) {}

Point &Point::operator=(const Point &other)
{
	(void)(other);
	return *this;
}

Point::~Point() {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "(" << point.x << ", " << point.y << ")";
	return os;
}