/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sykawai <sykawai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:20:53 by sykawai           #+#    #+#             */
/*   Updated: 2025/12/19 14:20:55 by sykawai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		static bool isCharLiteral(const std::string &literal);
		static bool isIntLiteral(const std::string &literal);
		static bool isFloatLiteral(const std::string &literal);
		static bool isDoubleLiteral(const std::string &literal);
		static bool isPseudoFloat(const std::string &literal);
		static bool isPseudoDouble(const std::string &literal);
		static void printFromDouble(double value, bool wasFloatLiteral);
		static void printPseudo(const std::string &literal);

	public:
		static void convert(const std::string &literal);
};

#endif
