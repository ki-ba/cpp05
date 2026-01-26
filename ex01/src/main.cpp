/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:46:15 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 09:03:54 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

#define GENERIC_ERROR "a fraudulent form was intercepted : "

int	main(void)
{
	Bureaucrat a("Anne", 43);
	Bureaucrat b("Billy", 102);
	Form l42;

	try{Form fauxForm("revolution manifest", false, 0, 42);}
	catch(std::exception &e){std::cout << GENERIC_ERROR << e.what();}

	try{Form fauxForm("petition for labor rights", false, 151, 42);}
	catch(std::exception &e){std::cout << GENERIC_ERROR << e.what();}

	try{Form fauxForm("interns lives matter campaign", false, 42, 0);}
	catch(std::exception &e){std::cout << GENERIC_ERROR << e.what();}

	try{Form fauxForm("paid vacation form", true, 42, 151);}
	catch(std::exception &e){std::cout << GENERIC_ERROR << e.what();}
	a.signForm(l42);
	a.promote();
	a.signForm(l42);
	return (0);
}
