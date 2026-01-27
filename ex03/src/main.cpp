/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:46:15 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/27 16:25:03 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#define GENERIC_ERROR "a fraudulent form was intercepted : "

int	main(void)
{
	Bureaucrat a("Anne", 43);
	Bureaucrat b("Billy", 102);
	Bureaucrat c("Marl Kax", 2);
	Intern intern;
	AForm *form;
	AForm *form2;
	AForm *form3;
	AForm *noForm;

	form = intern.makeForm("robotomy request form", "billy");
	form2 = intern.makeForm("shrubbery creation form", "presidential palace");
	form3 = intern.makeForm("presidential pardon form", "Anne");


	// no such form
	noForm = intern.makeForm("lunch break duration extension form", "Anne");


	(void)noForm; // null
	a.signForm(*form);
	a.signForm(*form2);
	a.signForm(*form3); // should not work : grade too low
	c.signForm(*form3);
	a.executeForm(*form);
	a.executeForm(*form2);
	a.executeForm(*form3); // should not work : grade too low

	delete form;
	delete form2;
	delete form3;
	return (0);
}
