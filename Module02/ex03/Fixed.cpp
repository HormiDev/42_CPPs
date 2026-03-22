/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:33:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/21 04:35:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << GREEN << "Default constructor called" << RESET << std::endl;
	this->value = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << MAGENTA << "Copy assignment operator called" << RESET << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const 
{
	std::cout << YELLOW << "getRawBits member function called" << RESET << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << MAGENTA << "setRawBits member function called" << RESET << std::endl;
	this->value = raw;
}

Fixed::Fixed(int value)
{
	std::cout << GREEN << "Int constructor called" << RESET << std::endl;
	this->value = value << fractionalBits;
}

Fixed::Fixed(float value)
{
	std::cout << GREEN << "Float constructor called" << RESET << std::endl;
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