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
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat kawai("kawai", 1);
		Bureaucrat syuto("syuto", 150);
		
		Form taxForm("Tax Form", 100, 50);

		std::cout << kawai << std::endl;
		std::cout << syuto << std::endl;
		std::cout << taxForm << std::endl;

		kawai.signForm(taxForm);
		syuto.signForm(taxForm);
	}
	catch(std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
