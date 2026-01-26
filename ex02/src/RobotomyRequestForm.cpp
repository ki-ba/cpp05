/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:04:08 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 16:15:38 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", false, ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	this->_target = other._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this == &other)
		return *this;
	AForm::operator=(other);
	this->_target = other._target;
	return *this;
}

void RobotomyRequestForm::make_action() const
{
	std::cout << "bzzzzzz.. ZZZZKK vvvvvv *ziiip*" << std::endl;
	if (true) //FIXME:
		std::cout << "Robotomy successful." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
		
}
RobotomyRequestForm::~RobotomyRequestForm()
{}
