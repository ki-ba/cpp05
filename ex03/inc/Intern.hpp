/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:58:08 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/27 16:19:58 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	// No parameterized constructor bc what parameter would that be?
	Intern(const Intern &other); // makes no sense since no member variable
	Intern &operator=(const Intern &other); // same
	AForm *makeShrubberyCreationForm(std::string target) const;
	AForm *makePresidentialPardonForm(std::string target) const;
	AForm *makeRobotomyRequestForm(std::string target) const;

public:
	Intern();
	~Intern();
	AForm *makeForm(std::string name, std::string target) const;

};

#endif
