/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 10:43:27 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/23 13:30:39 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	for (int i = 0; i <= 151; ++i)
	{
		try
		{
			Bureaucrat a("Amelie", i);
			std::cout << a << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "caught : " << e.what();
		}
	}

	Bureaucrat b("Benjamin", 1);
	try{b.promote();}
	catch (std::exception &e)
	{
		std::cout << "caught : " << e.what();
	}

	Bureaucrat c("Charlie", 150);
	try{c.demote();}
	catch (std::exception &e)
	{
		std::cout << "caught : " << e.what();
	}
}
