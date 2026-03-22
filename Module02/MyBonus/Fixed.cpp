/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:33:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/22 15:49:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const 
{
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::Fixed(int value)
{
	this->value = value << fractionalBits;
}

Fixed::Fixed(float value)
{
	this->value = roundf(value * (1 << fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return (float)this->value / (1 << fractionalBits);
}

int	Fixed::toInt(void) const
{
	return this->value / (1 << fractionalBits);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return o;
}

bool	Fixed::operator>(const Fixed &other) const
{
	return this->value > other.value;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->value < other.value;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->value >= other.value;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->value <= other.value;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->value == other.value;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->value != other.value;
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);
	this->value++;
	return temp;
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->value--;
	return temp;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;
}