/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 00:32:57 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/03/21 04:35:25 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Fixed
{
private:
	int 				value;
	static const int	fractionalBits = 8;
public:
						Fixed();
						Fixed(const Fixed &other);
						~Fixed();
	Fixed				&operator=(const Fixed &other);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
						Fixed(int value);
						Fixed(float value);
	float				toFloat(void) const;
	int					toInt(void) const;
	friend std::ostream	&operator<<(std::ostream &out, Fixed const &fix);
	bool				operator>(const Fixed &other) const;
	bool				operator<(const Fixed &other) const;
	bool				operator>=(const Fixed &other) const;
	bool				operator<=(const Fixed &other) const;
	bool				operator==(const Fixed &other) const;
	bool				operator!=(const Fixed &other) const;
	Fixed				operator+(const Fixed &other) const;
	Fixed				operator-(const Fixed &other) const;
	Fixed				operator*(const Fixed &other) const;
	Fixed				operator/(const Fixed &other) const;
	Fixed				&operator++(void);
	Fixed				operator++(int);
	Fixed				&operator--(void);
	Fixed				operator--(int);
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

#endif