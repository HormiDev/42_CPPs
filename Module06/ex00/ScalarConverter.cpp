/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 04:44:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/10/07 14:32:05 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::checkFloatFormat(const std::string &literal, const char *endPtr)
{
	if ((*endPtr != 'f' && *endPtr != 'F') || endPtr[1] != '\0')
		return false;

	bool hasPointOrExponent = false;
	// strtod already checked the syntax up to endPtr.
	for (const char *ptr = literal.c_str(); ptr != endPtr; ++ptr)
	{
		if (*ptr == '.' || *ptr == 'e' || *ptr == 'E')
			hasPointOrExponent = true;
		else if ((*ptr < '0' || *ptr > '9') && *ptr != '+' && *ptr != '-')
			return false;
	}
	return hasPointOrExponent;
}

static std::string formatFloatingPoint(double value)
{
	std::ostringstream stream;
	stream << value;
	std::string formatted = stream.str();
	if (formatted.find_first_not_of("+-0123456789") == std::string::npos)
		formatted += ".0";
	return formatted;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.empty())
	{
		std::cerr << "Error: Empty literal." << std::endl;
		return;
	}
	char *endPtr = 0;
	double value = std::strtod(literal.c_str(), &endPtr);

	if (literal == "+inf" || literal == "inf" || literal == "-inf" || literal == "nan"
		|| literal == "+inff" || literal == "inff" || literal == "-inff" || literal == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (literal == "+inf" || literal == "inf" || literal == "-inf" || literal == "nan")
		{
			std::cout << "float: " << literal << "f" << std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		else
		{
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
		}
		return;
	}

	if (*endPtr != '\0' && *endPtr != 'f' && *endPtr != 'F')
	{
		std::cerr << "Error: Invalid literal." << std::endl;
		return;
	}

	if ((*endPtr == 'f' || *endPtr == 'F') && !checkFloatFormat(literal, endPtr))
	{
		std::cerr << "Error: Invalid literal." << std::endl;
		return;
	}

	std::cout << "char: ";
	if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<char>(value)))
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	
	std::cout << "int: ";
	if (value < -2147483648 || value > 2147483647)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	std::cout << "float: ";
	if (value < -3.4028235e+38f || value > 3.4028235e+38f)
		std::cout << "impossible" << std::endl;
	else
		std::cout << formatFloatingPoint(static_cast<float>(value)) << "f" << std::endl;
	
	std::cout << "double: ";
	if (value < -1.7976931348623157e+308 || value > 1.7976931348623157e+308)
		std::cout << "impossible" << std::endl;
	else
		std::cout << formatFloatingPoint(value) << std::endl;
}
