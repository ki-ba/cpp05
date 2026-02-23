/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:46:15 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 18:02:16 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define GENERIC_ERROR "a fraudulent form was intercepted : "

int	main(void)
{
	Bureaucrat a("Anne", 43);
	Bureaucrat b("Billy", 102);
	RobotomyRequestForm r42("John Doe");
	PresidentialPardonForm p42("Jane Doe");
	ShrubberyCreationForm s42("Garden");
	ShrubberyCreationForm s43("Park");


	a.signForm(s42);
	a.signForm(s43);
	a.executeForm(s42);
	a.executeForm(s43);

	a.promote();
	a.signForm(r42);
	// a.signForm(p42);
	a.executeForm(r42);
	a.executeForm(p42);
	return (0);
}
