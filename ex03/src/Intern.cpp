/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 15:01:54 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/27 16:13:36 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{}

Intern::~Intern()
{}

AForm *Intern::makeShrubberyCreationForm(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target) const
{
	return(new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target) const
{
	return(new RobotomyRequestForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target) const
{
	std::string possibleNames[3] = {"shrubbery creation form", "robotomy request form", "presidential pardon form"};
	AForm *(Intern::*creators[3])(std::string) const;
	AForm *form = NULL;

	creators[0] = &Intern::makeShrubberyCreationForm;
	creators[1] = &Intern::makeRobotomyRequestForm;
	creators[2] = &Intern::makePresidentialPardonForm;

	for (int i = 0; i < 3; ++i)
	{
		if (name != possibleNames[i])
			continue;
		std::cout << "Intern creates " << name << std::endl;
		return(this->*creators[i])(target);

	}
	std::cout << "Intern does not know this form." << std::endl;
	return (form);
}


