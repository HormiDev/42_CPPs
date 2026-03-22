/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 21:20:44 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/22 02:31:15 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const x;
	Fixed const y;

public:
						Point();
						Point(float x, float y);
						Point(const Point &other);
						~Point();
	Point				&operator=(const Point &other);

						Point(const Fixed &x, const Fixed &y);
	Fixed				getX() const;
	Fixed				getY() const;
	friend std::ostream	&operator<<(std::ostream &os, const Point &point);
};

#endif // POINT_HPP