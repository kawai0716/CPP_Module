/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sykawai <sykawai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:56:56 by sykawai           #+#    #+#             */
/*   Updated: 2025/12/16 16:01:17 by sykawai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


// int main()
// {
// 	try
// 	{
// 		Bureaucrat boss("Boss", 1);
// 		Bureaucrat clerk("Clerk", 140);
// 		Bureaucrat low("Low", 150);
// 		Intern someIntern;
//
// 		AForm *shrub = someIntern.makeForm("shrubbery creation", "home");
// 		AForm *robo = someIntern.makeForm("robotomy request", "Bender");
// 		AForm *pardon = someIntern.makeForm("presidential pardon", "Arthur Dent");
// 		AForm *unknown = someIntern.makeForm("unknown form", "nobody");
//
// 		if (shrub)
// 		{
// 			clerk.signForm(*shrub);
// 			low.executeForm(*shrub);
// 			boss.executeForm(*shrub);
// 		}
//
// 		if (robo)
// 		{
// 			boss.signForm(*robo);
// 			boss.executeForm(*robo);
// 		}
//
// 		if (pardon)
// 		{
// 			boss.signForm(*pardon);
// 			boss.executeForm(*pardon);
// 		}
//
// 		delete shrub;
// 		delete robo;
// 		delete pardon;
// 		delete unknown;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Error: " << e.what() << std::endl;
// 	}
//
// 	return 0;
// }

int main()
{
	try
	{
		Intern intern;
		Bureaucrat executor("Exec", 1);

		AForm *form = intern.makeForm("shrubbery creation", "home");
		if (form)
		{
			executor.signForm(*form);
			executor.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
