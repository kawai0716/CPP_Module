/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sykawai <sykawai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:20:25 by sykawai           #+#    #+#             */
/*   Updated: 2025/12/19 14:20:27 by sykawai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	const std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};

	AForm *(Intern::*creators[])(const std::string &) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential};

	for (int i = 0; i < 3; ++i)
	{
		if (name == names[i])
		{
			AForm *form = (this->*creators[i])(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern cannot create form: unknown name \"" << name << "\"" << std::endl;
	return NULL;
}
