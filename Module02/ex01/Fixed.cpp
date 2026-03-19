/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:33:03 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/19 13:52:03 by ide-dieg         ###   ########.fr       */
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