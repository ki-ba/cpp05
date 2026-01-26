/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:16:37 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 09:16:00 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#ifdef FORMS
# ifdef EX02
#  include "AForm.hpp"
# else
# include "Form.hpp"
#endif
#endif

Bureaucrat::Bureaucrat() : _name("John"), _grade(0)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat()
{}

int	Bureaucrat::promote()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	return (--this->_grade);

}

int Bureaucrat::demote()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	return (++this->_grade);
}

#ifdef FORMS
void	Bureaucrat::signForm(FORM_TYPE &f)
{
	try{f.beSigned(*this);}
	catch(std::exception &e)
	{
		std::cout << *this << " couldn't sign " << f << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << *this << " signed " << f << std::endl;
}
#endif

#ifdef EX02
void	Bureaucrat::executeForm(FORM_TYPE const & form) const
{
	try{form.execute(*this);}
	catch(std::exception &e)
	{
		std::cout << *this << " couldn't execute " << form << " because " << e.what();
	}
}
#endif
std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}


Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) throw()
{
	os << "[" << b.getName() << ", bureaucrat grade " << b.getGrade() << "]";
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::range_error("Bureaucrat : grade can't be higher than 1\n")
{
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

Bureaucrat::GradeTooLowException::GradeTooLowException() : std::range_error("Bureaucrat : grade can't be lower than 150\n")
{
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}

