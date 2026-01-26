/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 08:25:38 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 15:26:52 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
# define FORM_HPP


#  include <string>
#  include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				 _signed;
	const int			_sign_grade;
	const int 			_exec_grade;
	Form &operator=(Form& other); // private bc makes no sense since only 1 attribute is non-const

public:
	Form();
	Form(Form &other);
	Form(const std::string name, bool is_signed, const int sign_grade, const int exec_grade);
	~Form();
	void	beSigned(Bureaucrat b);
	std::string	getName() const;
	int	getSignGrade() const;
	int	getExecGrade() const;
	bool	isSigned() const;


	class GradeTooHighException : public std::range_error
	{
		public:
			GradeTooHighException();
			GradeTooHighException(std::string msg);
			~GradeTooHighException() throw();
	};
	class GradeTooLowException : public std::range_error
	{
		public:
			GradeTooLowException();
			GradeTooLowException(std::string msg);
			~GradeTooLowException() throw();
	};

};

std::ostream &operator<<(std::ostream& os, Form &f) throw();
#endif

