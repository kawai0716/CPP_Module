/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sykawai <sykawai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:56:56 by sykawai           #+#    #+#             */
/*   Updated: 2025/11/27 15:56:56 by sykawai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat kawai("kawai", 1);
		std::cout << kawai << std::endl;

		kawai.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat syuto("syuto", 150);
		std::cout << syuto << std::endl;

		syuto.decrementGrade();
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}