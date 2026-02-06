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
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat clerk("Clerk", 140);
		Bureaucrat intern("Intern", 150);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robo("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << boss << std::endl;
		std::cout << clerk << std::endl;
		std::cout << intern << std::endl;

		clerk.signForm(shrub);
		intern.executeForm(shrub); // should fail: grade too low to execute
		boss.executeForm(shrub);

		boss.signForm(robo);
		boss.executeForm(robo);

		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
