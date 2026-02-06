/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sykawai <sykawai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:20:48 by sykawai           #+#    #+#             */
/*   Updated: 2025/12/19 14:20:50 by sykawai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isCharLiteral(const std::string &literal)
{
	return literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'' && std::isprint(literal[1]);
}

bool ScalarConverter::isIntLiteral(const std::string &literal)
{
	if (literal.empty())
		return false;
	std::size_t i = 0;
	if (literal[i] == '+' || literal[i] == '-')
		++i;
	if (i == literal.size())
		return false;
	for (; i < literal.size(); ++i)
	{
		if (!std::isdigit(literal[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloatLiteral(const std::string &literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;
	if (literal.size() < 2 || literal[literal.size() - 1] != 'f')
		return false;
	std::string core = literal.substr(0, literal.size() - 1);
	bool hasDot = false;
	std::size_t i = 0;
	if (core[i] == '+' || core[i] == '-')
		++i;
	if (i == core.size())
		return false;
	for (; i < core.size(); ++i)
	{
		if (core[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(core[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isDoubleLiteral(const std::string &literal)
{
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;
	bool hasDot = false;
	std::size_t i = 0;
	if (literal.empty())
		return false;
	if (literal[i] == '+' || literal[i] == '-')
		++i;
	if (i == literal.size())
		return false;
	for (; i < literal.size(); ++i)
	{
		if (literal[i] == '.')
		{
			if (hasDot)
				return false;
			hasDot = true;
		}
		else if (!std::isdigit(literal[i]))
			return false;
	}
	return hasDot;
}

bool ScalarConverter::isPseudoFloat(const std::string &literal)
{
	return literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool ScalarConverter::isPseudoDouble(const std::string &literal)
{
	return literal == "-inf" || literal == "+inf" || literal == "nan";
}

void ScalarConverter::printPseudo(const std::string &literal)
{
	std::string floatRep;
	std::string doubleRep;
	if (literal == "nanf" || literal == "nan")
	{
		floatRep = "nanf";
		doubleRep = "nan";
	}
	else if (literal[0] == '-')
	{
		floatRep = "-inff";
		doubleRep = "-inf";
	}
	else
	{
		floatRep = "+inff";
		doubleRep = "+inf";
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatRep << std::endl;
	std::cout << "double: " << doubleRep << std::endl;
}

void ScalarConverter::printFromDouble(double value, bool wasFloatLiteral)
{
	// char
	if (value != value || value == std::numeric_limits<double>::infinity() ||
		value == -std::numeric_limits<double>::infinity() || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

	// int
	if (value != value || value > static_cast<double>(std::numeric_limits<int>::max()) ||
		value < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;

	// float / double formatting
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << value << std::endl;
	if (!wasFloatLiteral)
		std::cout.unsetf(std::ios::floatfield);
}

void ScalarConverter::convert(const std::string &literal)
{
	if (isCharLiteral(literal))
	{
		char c = literal[1];
		printFromDouble(static_cast<double>(c), false);
		return;
	}

	if (isPseudoFloat(literal) || isPseudoDouble(literal))
	{
		printPseudo(literal);
		return;
	}

	if (isIntLiteral(literal))
	{
		long val = std::strtol(literal.c_str(), NULL, 10);
		printFromDouble(static_cast<double>(val), false);
		return;
	}

	if (isFloatLiteral(literal))
	{
		double val = std::strtod(literal.c_str(), NULL);
		printFromDouble(val, true);
		return;
	}

	if (isDoubleLiteral(literal))
	{
		double val = std::strtod(literal.c_str(), NULL);
		printFromDouble(val, false);
		return;
	}

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
