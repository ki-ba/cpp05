/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:32:35 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 09:14:31 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("42L"), _signed(false), _sign_grade(42), _exec_grade(101)
{
}

Form::Form(Form &other) :  _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	if (this->_sign_grade > 150)
		throw GradeTooLowException("sign grade too low\n");
	else if (this->_exec_grade > 150)
		throw GradeTooLowException("exec grade too low\n");
	if (this->_sign_grade < 1)
		throw GradeTooHighException("sign grade too high\n");
	else if (this->_exec_grade < 1)
		throw GradeTooHighException("exec grade too high\n");
}

Form::Form(const std::string name, bool is_signed, const int sign_grade, const int exec_grade) : _name(name),_signed(is_signed), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (this->_sign_grade > 150)
		throw GradeTooLowException("sign grade too low\n");
	else if (this->_exec_grade > 150)
		throw GradeTooLowException("exec grade too low\n");
	if (this->_sign_grade < 1)
		throw GradeTooHighException("sign grade too high\n");
	else if (this->_exec_grade < 1)
		throw GradeTooHighException("exec grade too high\n");
}

Form::~Form()
{}

void	Form::beSigned(Bureaucrat b)
{
	if (b.getGrade() > this->_sign_grade)
		throw GradeTooLowException("bureaucrat grade is too low");
	this->_signed = true;
}

std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getSignGrade() const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->_exec_grade);
}

bool	Form::isSigned() const
{
	return (this->_signed);
}

std::ostream &operator<<(std::ostream &os, Form &f) throw()
{
	os << "[Form " << f.getName() << ", signed : " << (f.isSigned() ? "yes" : "no" ) << ", " << "required sign grade : " << f.getSignGrade() << ", required exec grade : " << f.getExecGrade() << "]";
	return (os);
}

Form::GradeTooHighException::GradeTooHighException() : std::range_error("Form : ranges can't be higher than 1\n")
{}

Form::GradeTooHighException::GradeTooHighException(std::string msg) : std::range_error(msg)
{}

Form::GradeTooHighException::~GradeTooHighException() throw()
{}

Form::GradeTooLowException::GradeTooLowException() : std::range_error("Form : ranges can't lower than 150\n")
{}

Form::GradeTooLowException::GradeTooLowException(std::string msg) : std::range_error(msg)
{}

Form::GradeTooLowException::~GradeTooLowException() throw()
{}

