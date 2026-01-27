/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:32:35 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 16:21:51 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

AForm::AForm() : _name("42L"), _signed(false), _sign_grade(42), _exec_grade(101)
{}

AForm::AForm(const AForm &other) :  _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
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

AForm::AForm(const std::string name, bool is_signed, const int sign_grade, const int exec_grade) : _name(name),_signed(is_signed), _sign_grade(sign_grade), _exec_grade(exec_grade)
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

AForm::~AForm()
{}

void	AForm::beSigned(Bureaucrat b)
{
	if (b.getGrade() > this->_sign_grade)
		throw GradeTooLowException("bureaucrat grade is too low");
	this->_signed = true;
}

std::string	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getSignGrade() const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade() const
{
	return (this->_exec_grade);
}

bool	AForm::isSigned() const
{
	return (this->_signed);
}

AForm	&AForm::operator=(const AForm& other)
{
	if (this == &other)
		return (*this);
	this->_signed = other._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &f) throw()
{
	os << "[AForm " << f.getName() << ", signed : " << (f.isSigned() ? "yes" : "no" ) << ", " << "required sign grade : " << f.getSignGrade() << ", required exec grade : " << f.getExecGrade() << "]";
	return (os);
}

AForm::GradeTooHighException::GradeTooHighException() : std::range_error("AForm : ranges can't be higher than 1\n")
{}

AForm::GradeTooHighException::GradeTooHighException(std::string msg) : std::range_error(msg)
{}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{}

AForm::GradeTooLowException::GradeTooLowException() : std::range_error("AForm : ranges can't lower than 150\n")
{}

AForm::GradeTooLowException::GradeTooLowException(std::string msg) : std::range_error(msg)
{}

AForm::GradeTooLowException::~GradeTooLowException() throw()
{}

AForm::FormNotSignedException::FormNotSignedException() : std::runtime_error("AForm : not signed\n")
{}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->_exec_grade)
		throw GradeTooLowException("Executor grade to low\n");
	else
		this->make_action();
}

void AForm::make_action() const
{
	std::cout << "this form is so obscure no one can tell how to execute it." << std::endl;
}
